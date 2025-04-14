#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#define WIDTH 1024   // Largeur de l'image
#define HEIGHT 768   // Hauteur de l'image
#define N_FFT 512    // Taille de la FFT
#define SAMPLE_RATE 44100  // Fréquence d'échantillonnage (par exemple, 44.1 kHz)

// Paramètres de synchronisation VGA pour 1024x768 @ 60Hz
#define H_VISIBLE      1024   // Largeur visible
#define H_FRONT_PORCH  24     // Porche avant horizontal
#define H_SYNC_PULSE   136    // Durée de la pulsation de synchronisation horizontale
#define H_BACK_PORCH   160    // Porche arrière horizontal
#define H_TOTAL        (H_VISIBLE + H_FRONT_PORCH + H_SYNC_PULSE + H_BACK_PORCH)  // Largeur totale de la ligne

#define V_VISIBLE      768    // Hauteur visible
#define V_FRONT_PORCH  3      // Porche avant vertical
#define V_SYNC_PULSE   6      // Durée de la pulsation de synchronisation verticale
#define V_BACK_PORCH   29     // Porche arrière vertical
#define V_TOTAL        (V_VISIBLE + V_FRONT_PORCH + V_SYNC_PULSE + V_BACK_PORCH)  // Hauteur totale de l'image

// Structure pour représenter un nombre complexe
typedef struct {
    float real;
    float imag;
} Complex;

// Simulation du transfert de données par DMA (dans la réalité, le DMA copie les résultats FFT de la mémoire vers le processeur)
void dma_transfer(Complex *fft_data, float *magnitude, int N) {
    // Simule un transfert de données depuis la mémoire (via DMA) vers le tableau de données FFT du processeur
    for (int i = 0; i < N; i++) {
        magnitude[i] = sqrt(fft_data[i].real * fft_data[i].real + fft_data[i].imag * fft_data[i].imag);
    }
}

// Fonction pour créer l'image à partir des données FFT
void createImage(float *magnitude, SDL_Renderer *renderer, int width, int height, int N) {
    int max_magnitude = 0;

    // Trouver la magnitude maximale pour le scaling
    for (int i = 0; i < N; i++) {
        if (magnitude[i] > max_magnitude) {
            max_magnitude = magnitude[i];
        }
    }

    // Dessiner les données FFT sous forme d'image
    for (int x = 0; x < N && x < width; x++) {
        int y = (int)((magnitude[x] / max_magnitude) * height);
        SDL_SetRenderDrawColor(renderer, 255, 255 - (y * 255 / height), 0, 255); // Couleur dynamique
        SDL_RenderDrawLine(renderer, x, height, x, height - y); // Dessiner la ligne pour chaque point
    }

    // Ajouter les axes pour les fréquences et amplitudes
    // Axe X (fréquences)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Blanc
    for (int i = 0; i < N; i += N / 10) {  // Placer des marques tous les 10% de la largeur
        int freq = i * SAMPLE_RATE / N;  // Calculer la fréquence associée à chaque bande
        SDL_RenderDrawLine(renderer, i, height, i, height - 10); // Marque de fréquence
    }

    // Axe Y (amplitude)
    for (int i = 0; i < height; i += height / 5) {  // Marquer 5 niveaux d'amplitude
        SDL_RenderDrawLine(renderer, 0, i, 10, i);  // Marque d'amplitude
    }
}

// Fonction pour simuler le signal VGA (et afficher les pixels)
void vga_simulation(SDL_Renderer *renderer) {
    int h_count = 0, v_count = 0;  // Comptage horizontal et vertical
    int vga_clk = 0;  // Signal de l'horloge VGA simulée
    SDL_Event event;
    int quit = 0;

    // Simulation de la fréquence d'horloge VGA (65MHz)
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Simuler l'horloge VGA (en vrai, ce serait généré par un PLL)
        vga_clk = !vga_clk;

        if (vga_clk) {
            // Comptage horizontal
            if (h_count == H_TOTAL - 1) {
                h_count = 0;
                // Comptage vertical
                if (v_count == V_TOTAL - 1) {
                    v_count = 0;  // Redémarre le comptage vertical
                } else {
                    v_count++;
                }
            } else {
                h_count++;
            }

            // Synchronisation des signaux VGA
            int h_sync = (h_count >= (WIDTH + H_FRONT_PORCH)) && (h_count < (WIDTH + H_FRONT_PORCH + H_SYNC_PULSE)) ? 0 : 1;
            int v_sync = (v_count >= (HEIGHT + V_FRONT_PORCH)) && (v_count < (HEIGHT + V_FRONT_PORCH + V_SYNC_PULSE)) ? 0 : 1;
            
            // Déterminer si on est dans la zone visible
            int display_on = (h_count < WIDTH) && (v_count < HEIGHT);
            if (display_on) {
                // Calcul de l'adresse mémoire simulée pour l'affichage des pixels
                int addr = v_count * WIDTH + h_count;
                
                // Simuler l'affichage des pixels
                unsigned short pixel_data = (rand() % 4096);  // Valeur de pixel simulée, dans la plage 12 bits
                SDL_RenderDrawPoint(renderer, h_count, v_count); // Afficher un pixel
            }

            // Synchronisation du rendu
            SDL_RenderPresent(renderer);
        }
        SDL_Delay(10);  // Délai pour simuler la fréquence d'horloge
    }
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("FFT Data to Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Simulation des données FFT (par exemple, avec des valeurs aléatoires)
    Complex fft_data[N_FFT];
    float magnitude[N_FFT];

    // Initialiser les données FFT avec des valeurs aléatoires
    for (int i = 0; i < N_FFT; i++) {
        fft_data[i].real = (rand() % 1000) / 100.0f;  // Valeur réelle aléatoire
        fft_data[i].imag = (rand() % 1000) / 100.0f; // Valeur imaginaire aléatoire
    }

    // Simulation du transfert de données via DMA
    dma_transfer(fft_data, magnitude, N_FFT);

    // Effacer l'écran
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Créer l'image à partir des données FFT
    createImage(magnitude, renderer, WIDTH, HEIGHT, N_FFT);

    // Appeler la simulation du signal VGA
    vga_simulation(renderer);

    // Libérer les ressources et fermer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
