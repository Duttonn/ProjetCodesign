library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity I2S_tb is
end I2S_tb;

architecture Behavioral of I2S_tb is

    -- Component Declaration
    component I2S
        Port (
            clk           : in  std_logic;
            rst           : in  std_logic;
            sdin          : in  std_logic;
            mclk          : out std_logic;
            lrclk         : out std_logic;
            bclk          : out std_logic;
            m_axis_tdata  : out std_logic_vector(31 downto 0);
            m_axis_tvalid : out std_logic;
            m_axis_tlast  : out std_logic;
            m_axis_tready : in  std_logic
        );
    end component;

    -- Signals
    signal clk           : std_logic := '0';
    signal rst           : std_logic := '0';
    signal sdin          : std_logic := '0';
    signal mclk          : std_logic;
    signal lrclk         : std_logic;
    signal bclk          : std_logic;
    signal m_axis_tdata  : std_logic_vector(31 downto 0);
    signal m_axis_tvalid : std_logic;
    signal m_axis_tlast  : std_logic;
    signal m_axis_tready : std_logic := '1';

    constant CLK_PERIOD : time := 10 ns;

begin

    -- DUT Instantiation
    uut: I2S
        port map (
            clk           => clk,
            rst           => rst,
            sdin          => sdin,
            mclk          => mclk,
            lrclk         => lrclk,
            bclk          => bclk,
            m_axis_tdata  => m_axis_tdata,
            m_axis_tvalid => m_axis_tvalid,
            m_axis_tlast  => m_axis_tlast,
            m_axis_tready => m_axis_tready
        );

    -- Clock generation
    clk_process : process
    begin
        while now < 5 ms loop
            clk <= '0';
            wait for CLK_PERIOD / 2;
            clk <= '1';
            wait for CLK_PERIOD / 2;
        end loop;
        wait;
    end process;

    -- Stimulus process
    stimulus : process
        variable left_data  : std_logic_vector(23 downto 0) := x"0FFFFF";
        variable right_data : std_logic_vector(23 downto 0) := x"F0F0F0";
        variable i : integer;
    begin
        -- Reset
        rst <= '0';
        wait for 100 ns;
        rst <= '1';

        wait for 100 ns;
    while m_axis_tlast = '0' loop

        -- Attente du front montant de LRCLK pour gauche
        wait until rising_edge(lrclk);
        wait until falling_edge(bclk);

        -- Envoyer gauche : 0x0FFFFF
        for i in 23 downto 0 loop
            sdin <= left_data(i);
            wait until falling_edge(bclk);
        end loop;

        -- Attente du front descendant de LRCLK pour droite
        wait until falling_edge(lrclk);
        wait until falling_edge(bclk);

        -- Envoyer droite : 0xF0F0F0
        for i in 23 downto 0 loop
            sdin <= right_data(i);
            wait until falling_edge(bclk);
        end loop;


    end loop;
    
        wait for 100 ns;

        -- Fin
        wait;
    end process;

end Behavioral;
