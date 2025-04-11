library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity I2S is
    Port (
        clk           : in  std_logic;
        rst           : in  std_logic;
        sdin          : in  std_logic;

        -- Vers dongle
        mclk           : out std_logic;
        lrclk          : out std_logic;
        bclk           : out std_logic;

        -- AXI Stream (vers FiFo)
        m_axis_tdata   : out std_logic_vector(31 downto 0);
        m_axis_tvalid  : out std_logic;
        m_axis_tlast   : out std_logic;
        m_axis_tready  : in  std_logic
    );
end I2S;

architecture Behavioral of I2S is

    -- Horloge : division pour BCLK, LRCLK, MCLK
    signal diviseur       : std_logic_vector(9 downto 0) := (others => '0');
    signal s_bclk         : std_logic := '0';
    signal s_lrclk        : std_logic := '0';

    -- Data reception
    signal shift_reg     : std_logic_vector(23 downto 0) := (others => '0');
    signal bit_counter   : integer range 0 to 24 := 0;

    -- FSM
    type etat_I2S is (wait_r_chan, wait_l_chan, listen_r_chan, listen_l_chan);
    signal mae_i2s : etat_I2S := wait_r_chan;

    -- AXI stream
    signal axi_data_reg : std_logic_vector(31 downto 0) := (others => '0');
    signal valid_reg    : std_logic := '0';
    signal last_reg     : std_logic := '0';
    signal sample_count : integer range 0 to 512 := 0;
    signal valid_reg_prev : std_logic := '0';

begin

    -- Génération des horloges
    process(clk, rst)
    begin
        if rst = '0' then
            diviseur <= (others => '0');
            s_bclk   <= '0';
            s_lrclk  <= '0';
        elsif rising_edge(clk) then
            diviseur <= std_logic_vector(unsigned(diviseur) + 1);
            s_bclk   <= diviseur(2);
            s_lrclk  <= diviseur(8);
        end if;
    end process;

    lrclk <= s_lrclk;
    bclk  <= s_bclk;
    mclk  <= clk;  

    -- Data reception FSM
    process(s_bclk, rst)
    begin
        if rst = '0' then
            shift_reg     <= (others => '0');
            bit_counter   <= 0;
            mae_i2s       <= wait_r_chan;
            valid_reg     <= '0';
            axi_data_reg  <= (others => '0');
        elsif rising_edge(s_bclk) then
            case mae_i2s is

                when wait_r_chan =>
                    if s_lrclk = '1' then
                        valid_reg <= '0';
                        mae_i2s <= listen_r_chan;
                    end if;

                when wait_l_chan =>
                    if s_lrclk = '0' then
                        valid_reg <= '0';
                        mae_i2s <= listen_l_chan;
                    end if;

                when listen_r_chan =>
                    if bit_counter = 23 then
                        bit_counter <= 0;
                        mae_i2s <= wait_l_chan;
                        valid_reg <= '1';
                        last_reg  <= '1';
                        axi_data_reg(31 downto 25) <= (others => '0');
                        axi_data_reg(31)           <= '1';
                        axi_data_reg(23 downto 0)  <= shift_reg;
                        shift_reg <= (others => '0');
                    else
                        if bit_counter = 0 then
                            shift_reg <= (others => '0');
                        end if;
                        shift_reg <= shift_reg(22 downto 0) & sdin;
                        bit_counter <= bit_counter + 1;
                    end if;

                when listen_l_chan =>
                    if bit_counter = 23 then
                        bit_counter <= 0;
                        mae_i2s <= wait_r_chan;
                        valid_reg <= '1';
                        last_reg  <= '0';
                        axi_data_reg(31 downto 25) <= (others => '0');
                        axi_data_reg(31)           <= '0';
                        axi_data_reg(23 downto 0)  <= shift_reg;
                        shift_reg <= (others => '0');
                    else
                        if bit_counter = 0 then
                            shift_reg <= (others => '0');
                        end if;
                        shift_reg <= shift_reg(22 downto 0) & sdin;
                        bit_counter <= bit_counter + 1;
                    end if;

            end case;
        end if;
    end process;

    -- AXI stream output logic
 -- AXI stream output logic
 process(s_bclk)
 begin
     if rising_edge(s_bclk) then
         valid_reg_prev <= valid_reg;

         if m_axis_tready = '1' then
             m_axis_tvalid <= valid_reg;
             m_axis_tdata  <= axi_data_reg;

             if valid_reg = '1' and valid_reg_prev = '0' then 
                 if sample_count = 511 then
                     m_axis_tlast <= '1';
                     sample_count <= 0;
                 else
                     m_axis_tlast <= '0';
                     sample_count <= sample_count + 1;
                 end if;
             else
                 m_axis_tlast <= '0';
             end if;

         else
             m_axis_tvalid <= '0';
         end if;
     end if;
 end process;

end Behavioral;
