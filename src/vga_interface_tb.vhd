LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY vga_interface_tb IS
END ENTITY;

ARCHITECTURE Behavioral OF vga_interface_tb IS

    CONSTANT CLK_PERIOD : TIME := 20 ns; -- 50MHz clock period

    -- Input signals
    SIGNAL clk         : STD_LOGIC := '0';
    SIGNAL reset       : STD_LOGIC := '0';
    SIGNAL pixel_data  : STD_LOGIC_VECTOR(11 DOWNTO 0) := x"FFF"; -- White color by default
    
    -- Output signals
    SIGNAL h_sync      : STD_LOGIC;
    SIGNAL v_sync      : STD_LOGIC;
    SIGNAL red         : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL green       : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL blue        : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL pixel_x     : UNSIGNED(9 DOWNTO 0);
    SIGNAL pixel_y     : UNSIGNED(9 DOWNTO 0);
    SIGNAL video_on    : STD_LOGIC;

BEGIN

    -- Clock generation process
    clk_process : PROCESS
    BEGIN
        WHILE true LOOP
            clk <= '0';
            WAIT FOR CLK_PERIOD / 2;
            clk <= '1';
            WAIT FOR CLK_PERIOD / 2;
        END LOOP;
    END PROCESS;

    -- Device under test instantiation
    DUT : ENTITY work.vga_interface
        PORT MAP(
            clk         => clk,
            reset       => reset,
            pixel_data  => pixel_data,
            h_sync      => h_sync,
            v_sync      => v_sync,
            red         => red,
            green       => green,
            blue        => blue,
            pixel_x     => pixel_x,
            pixel_y     => pixel_y,
            video_on    => video_on
        );

    -- Stimulus process
    stimulus_process : PROCESS
    BEGIN
        -- Initial reset
        reset <= '1';
        WAIT FOR 100 ns;
        reset <= '0';
        
        -- Change pixel color values to test RGB output
        WAIT FOR 100 ns;
        pixel_data <= x"F00";  -- Red
        
        WAIT FOR 100 ns;
        pixel_data <= x"0F0";  -- Green
        
        WAIT FOR 100 ns;
        pixel_data <= x"00F";  -- Blue
        
        -- Run simulation for several frames to observe VGA timing
        WAIT FOR 20 ms;
        
        ASSERT false REPORT "Simulation complete." SEVERITY note;
        WAIT;
    END PROCESS;

END ARCHITECTURE;
