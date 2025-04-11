LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY vga_interface_tb IS
END ENTITY;

ARCHITECTURE Behavioral OF vga_interface_tb IS

    CONSTANT CLK_PERIOD : TIME := 20 ns; -- 50MHz clock period

    -- Input signals
    SIGNAL clk : STD_LOGIC := '0';
    SIGNAL reset : STD_LOGIC := '0';
    SIGNAL data_data : STD_LOGIC_VECTOR(11 DOWNTO 0) := x"FFF"; -- White color by default

    -- Memory address signal
    SIGNAL data_address : STD_LOGIC_VECTOR(20 DOWNTO 0);

    -- Output signals
    SIGNAL h_sync : STD_LOGIC;
    SIGNAL v_sync : STD_LOGIC;
    SIGNAL red : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL green : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL blue : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL video_on : STD_LOGIC;

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
            clk => clk,
            reset => reset,
            data_data => data_data,
            data_address => data_address,
            h_sync => h_sync,
            v_sync => v_sync,
            red => red,
            green => green,
            blue => blue,
            video_on => video_on
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
        data_data <= x"F00"; -- Red

        WAIT FOR 100 ns;
        data_data <= x"0F0"; -- Green

        WAIT FOR 100 ns;
        data_data <= x"00F"; -- Blue

        -- Run simulation for several frames to observe VGA timing
        WAIT FOR 20 ms;

        ASSERT false REPORT "Simulation complete." SEVERITY note;
        WAIT;
    END PROCESS;

END ARCHITECTURE;