library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity vga_interface is
    Port ( 
        -- Input signals
        clk         : in  STD_LOGIC;                     -- System clock (typically 50MHz)
        reset       : in  STD_LOGIC;                     -- Reset signal
        
        -- Data interface (replacing direct pixel_data)
        data_data   : in  STD_LOGIC_VECTOR(11 downto 0); -- Pixel color data from memory
        data_address: out STD_LOGIC_VECTOR(20 downto 0); -- Address for pixel data (can address 2^21 pixels)
        
        -- Output signals
        h_sync      : out STD_LOGIC;                     -- Horizontal sync
        v_sync      : out STD_LOGIC;                     -- Vertical sync
        red         : out STD_LOGIC_VECTOR(3 downto 0);  -- Red channel
        green       : out STD_LOGIC_VECTOR(3 downto 0);  -- Green channel
        blue        : out STD_LOGIC_VECTOR(3 downto 0);  -- Blue channel
        video_on    : out STD_LOGIC                      -- Video active flag
    );
end vga_interface;

architecture Behavioral of vga_interface is
    -- VGA 1024x768@60Hz timing parameters
    constant H_VISIBLE      : integer := 1024; -- Visible area width
    constant H_FRONT_PORCH  : integer := 24;   -- Front porch width
    constant H_SYNC_PULSE   : integer := 136;  -- Sync pulse width
    constant H_BACK_PORCH   : integer := 160;  -- Back porch width
    constant H_TOTAL        : integer := H_VISIBLE + H_FRONT_PORCH + H_SYNC_PULSE + H_BACK_PORCH;
    
    constant V_VISIBLE      : integer := 768;  -- Visible area height
    constant V_FRONT_PORCH  : integer := 3;    -- Front porch height
    constant V_SYNC_PULSE   : integer := 6;    -- Sync pulse height
    constant V_BACK_PORCH   : integer := 29;   -- Back porch height
    constant V_TOTAL        : integer := V_VISIBLE + V_FRONT_PORCH + V_SYNC_PULSE + V_BACK_PORCH;
    
    -- Internal signals
    signal h_count      : unsigned(10 downto 0) := (others => '0'); -- Horizontal counter (needs 11 bits for 1024)
    signal v_count      : unsigned(9 downto 0) := (others => '0');  -- Vertical counter
    signal h_display_on : std_logic;  -- Horizontal display active
    signal v_display_on : std_logic;  -- Vertical display active
    signal display_on   : std_logic;  -- Display active (both h and v)
    signal vga_clk      : std_logic := '0';  -- VGA clock (65MHz)
    
    -- PLL related signals (for 65MHz clock generation)
    signal clk_count    : unsigned(2 downto 0) := (others => '0');
    constant CLK_DIVIDER : integer := 0; -- Assuming external PLL or clock source for 65MHz
    
begin
    -- For a real implementation, you would need a PLL to generate 65MHz
    -- This is a placeholder for simulation purposes only
    -- In a real design, you would use your FPGA's PLL/clock manager IP
    process(clk, reset)
    begin
        if reset = '1' then
            vga_clk <= '0';
        elsif rising_edge(clk) then
            -- This is a placeholder. In practice, you'd use a PLL
            -- to generate 65MHz from your input clock
            vga_clk <= not vga_clk;
        end if;
    end process;
    
    -- Horizontal counter
    process(vga_clk, reset)
    begin
        if reset = '1' then
            h_count <= (others => '0');
        elsif rising_edge(vga_clk) then
            if h_count = H_TOTAL - 1 then
                h_count <= (others => '0');
            else
                h_count <= h_count + 1;
            end if;
        end if;
    end process;
    
    -- Vertical counter
    process(vga_clk, reset)
    begin
        if reset = '1' then
            v_count <= (others => '0');
        elsif rising_edge(vga_clk) then
            if h_count = H_TOTAL - 1 then
                if v_count = V_TOTAL - 1 then
                    v_count <= (others => '0');
                else
                    v_count <= v_count + 1;
                end if;
            end if;
        end if;
    end process;
    
    -- Horizontal and vertical sync signals
    h_sync <= '0' when (h_count >= (H_VISIBLE + H_FRONT_PORCH)) and 
                        (h_count < (H_VISIBLE + H_FRONT_PORCH + H_SYNC_PULSE)) else '1';
    
    v_sync <= '0' when (v_count >= (V_VISIBLE + V_FRONT_PORCH)) and 
                        (v_count < (V_VISIBLE + V_FRONT_PORCH + V_SYNC_PULSE)) else '1';
    
    -- Display active signals
    h_display_on <= '1' when h_count < H_VISIBLE else '0';
    v_display_on <= '1' when v_count < V_VISIBLE else '0';
    display_on <= h_display_on and v_display_on;
    
    -- Generate memory address based on current position
    -- Use a combined address calculation: row * width + column
    process(h_count, v_count, display_on)
    begin
        if display_on = '1' then
            -- Calculate pixel address: y * width + x
            -- For 1024x768 resolution: y * 1024 + x
            data_address <= std_logic_vector(resize(v_count * 1024 + h_count, 21));
        else
            -- Output a safe address when not in display area
            data_address <= (others => '0');
        end if;
    end process;
    
    -- Output RGB signals (using data_data instead of pixel_data)
    process(display_on, data_data)
    begin
        if display_on = '1' then
            red   <= data_data(11 downto 8);
            green <= data_data(7 downto 4);
            blue  <= data_data(3 downto 0);
        else
            red   <= (others => '0');
            green <= (others => '0');
            blue  <= (others => '0');
        end if;
    end process;
    
    -- Video active signal for external use
    video_on <= display_on;
    
end Behavioral;