# 0 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/system.dts"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/system.dts"
# 1 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/system-top.dts" 1







/dts-v1/;
# 1 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/zynq-7000.dtsi" 1
# 15 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/zynq-7000.dtsi"
/ {
 #address-cells = <1>;
 #size-cells = <1>;
 compatible = "xlnx,zynq-7000";

 cpus {
  #address-cells = <1>;
  #size-cells = <0>;

  cpu0: cpu@0 {
   compatible = "arm,cortex-a9";
   device_type = "cpu";
   reg = <0>;
   clocks = <&clkc 3>;
   clock-latency = <1000>;
   cpu0-supply = <&regulator_vccpint>;
   operating-points = <

    666667 1000000
    333334 1000000
   >;
  };

  cpu1: cpu@1 {
   compatible = "arm,cortex-a9";
   device_type = "cpu";
   reg = <1>;
   clocks = <&clkc 3>;
  };
 };

 fpga_full: fpga-full {
  compatible = "fpga-region";
  fpga-mgr = <&devcfg>;
  #address-cells = <1>;
  #size-cells = <1>;
  ranges;
 };

 pmu@f8891000 {
  compatible = "arm,cortex-a9-pmu";
  interrupts = <0 5 4>, <0 6 4>;
  interrupt-parent = <&intc>;
  reg = < 0xf8891000 0x1000 0xf8893000 0x1000 >;
 };

 regulator_vccpint: fixedregulator {
  compatible = "regulator-fixed";
  regulator-name = "VCCPINT";
  regulator-min-microvolt = <1000000>;
  regulator-max-microvolt = <1000000>;
  regulator-boot-on;
  regulator-always-on;
 };

 replicator {
  compatible = "arm,coresight-static-replicator";
  clocks = <&clkc 27>, <&clkc 46>, <&clkc 47>;
  clock-names = "apb_pclk", "dbg_trc", "dbg_apb";

  out-ports {
   #address-cells = <1>;
   #size-cells = <0>;


   port@0 {
    reg = <0>;
    replicator_out_port0: endpoint {
     remote-endpoint = <&tpiu_in_port>;
    };
   };
   port@1 {
    reg = <1>;
    replicator_out_port1: endpoint {
     remote-endpoint = <&etb_in_port>;
    };
   };
  };
  in-ports {

   port {
    replicator_in_port0: endpoint {
     remote-endpoint = <&funnel_out_port>;
    };
   };
  };
 };

 amba: axi {
  u-boot,dm-pre-reloc;
  compatible = "simple-bus";
  #address-cells = <1>;
  #size-cells = <1>;
  interrupt-parent = <&intc>;
  ranges;

  adc: adc@f8007100 {
   compatible = "xlnx,zynq-xadc-1.00.a";
   reg = <0xf8007100 0x20>;
   interrupts = <0 7 4>;
   interrupt-parent = <&intc>;
   clocks = <&clkc 12>;
  };

  can0: can@e0008000 {
   compatible = "xlnx,zynq-can-1.0";
   status = "disabled";
   clocks = <&clkc 19>, <&clkc 36>;
   clock-names = "can_clk", "pclk";
   reg = <0xe0008000 0x1000>;
   interrupts = <0 28 4>;
   interrupt-parent = <&intc>;
   tx-fifo-depth = <0x40>;
   rx-fifo-depth = <0x40>;
  };

  can1: can@e0009000 {
   compatible = "xlnx,zynq-can-1.0";
   status = "disabled";
   clocks = <&clkc 20>, <&clkc 37>;
   clock-names = "can_clk", "pclk";
   reg = <0xe0009000 0x1000>;
   interrupts = <0 51 4>;
   interrupt-parent = <&intc>;
   tx-fifo-depth = <0x40>;
   rx-fifo-depth = <0x40>;
  };

  gpio0: gpio@e000a000 {
   compatible = "xlnx,zynq-gpio-1.0";
   #gpio-cells = <2>;
   clocks = <&clkc 42>;
   gpio-controller;
   interrupt-controller;
   #interrupt-cells = <2>;
   interrupt-parent = <&intc>;
   interrupts = <0 20 4>;
   reg = <0xe000a000 0x1000>;
  };

  i2c0: i2c@e0004000 {
   compatible = "cdns,i2c-r1p10";
   status = "disabled";
   clocks = <&clkc 38>;
   interrupt-parent = <&intc>;
   interrupts = <0 25 4>;
   reg = <0xe0004000 0x1000>;
   #address-cells = <1>;
   #size-cells = <0>;
  };

  i2c1: i2c@e0005000 {
   compatible = "cdns,i2c-r1p10";
   status = "disabled";
   clocks = <&clkc 39>;
   interrupt-parent = <&intc>;
   interrupts = <0 48 4>;
   reg = <0xe0005000 0x1000>;
   #address-cells = <1>;
   #size-cells = <0>;
  };

  intc: interrupt-controller@f8f01000 {
   compatible = "arm,cortex-a9-gic";
   #interrupt-cells = <3>;
   interrupt-controller;
   reg = <0xF8F01000 0x1000>,
         <0xF8F00100 0x100>;
  };

  L2: cache-controller@f8f02000 {
   compatible = "arm,pl310-cache";
   reg = <0xF8F02000 0x1000>;
   interrupts = <0 2 4>;
   arm,data-latency = <3 2 2>;
   arm,tag-latency = <2 2 2>;
   cache-unified;
   cache-level = <2>;
  };

  mc: memory-controller@f8006000 {
   compatible = "xlnx,zynq-ddrc-a05";
   reg = <0xf8006000 0x1000>;
  };

  ocm: sram@fffc0000 {
   compatible = "mmio-sram";
   reg = <0xfffc0000 0x10000>;
  };

  uart0: serial@e0000000 {
   compatible = "xlnx,xuartps", "cdns,uart-r1p8";
   status = "disabled";
   clocks = <&clkc 23>, <&clkc 40>;
   clock-names = "uart_clk", "pclk";
   reg = <0xE0000000 0x1000>;
   interrupts = <0 27 4>;
  };

  uart1: serial@e0001000 {
   compatible = "xlnx,xuartps", "cdns,uart-r1p8";
   status = "disabled";
   clocks = <&clkc 24>, <&clkc 41>;
   clock-names = "uart_clk", "pclk";
   reg = <0xE0001000 0x1000>;
   interrupts = <0 50 4>;
  };

  spi0: spi@e0006000 {
   compatible = "xlnx,zynq-spi-r1p6";
   reg = <0xe0006000 0x1000>;
   status = "disabled";
   interrupt-parent = <&intc>;
   interrupts = <0 26 4>;
   clocks = <&clkc 25>, <&clkc 34>;
   clock-names = "ref_clk", "pclk";
   #address-cells = <1>;
   #size-cells = <0>;
  };

  spi1: spi@e0007000 {
   compatible = "xlnx,zynq-spi-r1p6";
   reg = <0xe0007000 0x1000>;
   status = "disabled";
   interrupt-parent = <&intc>;
   interrupts = <0 49 4>;
   clocks = <&clkc 26>, <&clkc 35>;
   clock-names = "ref_clk", "pclk";
   #address-cells = <1>;
   #size-cells = <0>;
  };

  qspi: spi@e000d000 {
   clock-names = "ref_clk", "pclk";
   clocks = <&clkc 10>, <&clkc 43>;
   compatible = "xlnx,zynq-qspi-1.0";
   status = "disabled";
   interrupt-parent = <&intc>;
   interrupts = <0 19 4>;
   reg = <0xe000d000 0x1000>;
   #address-cells = <1>;
   #size-cells = <0>;
  };

  gem0: ethernet@e000b000 {
   compatible = "xlnx,zynq-gem", "cdns,zynq-gem", "cdns,gem";
   reg = <0xe000b000 0x1000>;
   status = "disabled";
   interrupts = <0 22 4>;
   clocks = <&clkc 30>, <&clkc 30>, <&clkc 13>;
   clock-names = "pclk", "hclk", "tx_clk";
   #address-cells = <1>;
   #size-cells = <0>;
  };

  gem1: ethernet@e000c000 {
   compatible = "xlnx,zynq-gem", "cdns,zynq-gem", "cdns,gem";
   reg = <0xe000c000 0x1000>;
   status = "disabled";
   interrupts = <0 45 4>;
   clocks = <&clkc 31>, <&clkc 31>, <&clkc 14>;
   clock-names = "pclk", "hclk", "tx_clk";
   #address-cells = <1>;
   #size-cells = <0>;
  };

  smcc: memory-controller@e000e000 {
   compatible = "arm,pl353-smc-r2p1", "arm,primecell";
   reg = <0xe000e000 0x0001000>;
   status = "disabled";
   clock-names = "memclk", "apb_pclk";
   clocks = <&clkc 11>, <&clkc 44>;
   ranges = <0x0 0x0 0xe1000000 0x1000000
      0x1 0x0 0xe2000000 0x2000000
      0x2 0x0 0xe4000000 0x2000000>;
   #address-cells = <2>;
   #size-cells = <1>;
   interrupt-parent = <&intc>;
   interrupts = <0 18 4>;
   nfc0: nand-controller@0,0 {
    compatible = "arm,pl353-nand-r2p1";
    reg = <0 0 0x1000000>;
    status = "disabled";
    #address-cells = <0x1>;
    #size-cells = <0x0>;
   };
   nor0: flash@1,0 {
    status = "disabled";
    compatible = "cfi-flash";
    reg = <1 0 0x2000000>;
    #address-cells = <1>;
    #size-cells = <1>;
   };
  };

  sdhci0: mmc@e0100000 {
   compatible = "arasan,sdhci-8.9a";
   status = "disabled";
   clock-names = "clk_xin", "clk_ahb";
   clocks = <&clkc 21>, <&clkc 32>;
   interrupt-parent = <&intc>;
   interrupts = <0 24 4>;
   reg = <0xe0100000 0x1000>;
  };

  sdhci1: mmc@e0101000 {
   compatible = "arasan,sdhci-8.9a";
   status = "disabled";
   clock-names = "clk_xin", "clk_ahb";
   clocks = <&clkc 22>, <&clkc 33>;
   interrupt-parent = <&intc>;
   interrupts = <0 47 4>;
   reg = <0xe0101000 0x1000>;
  };

  slcr: slcr@f8000000 {
   u-boot,dm-pre-reloc;
   #address-cells = <1>;
   #size-cells = <1>;
   compatible = "xlnx,zynq-slcr", "syscon", "simple-mfd";
   reg = <0xF8000000 0x1000>;
   ranges;
   clkc: clkc@100 {
    u-boot,dm-pre-reloc;
    #clock-cells = <1>;
    compatible = "xlnx,ps7-clkc";
    fclk-enable = <0xf>;
    clock-output-names = "armpll", "ddrpll", "iopll", "cpu_6or4x",
      "cpu_3or2x", "cpu_2x", "cpu_1x", "ddr2x", "ddr3x",
      "dci", "lqspi", "smc", "pcap", "gem0", "gem1",
      "fclk0", "fclk1", "fclk2", "fclk3", "can0", "can1",
      "sdio0", "sdio1", "uart0", "uart1", "spi0", "spi1",
      "dma", "usb0_aper", "usb1_aper", "gem0_aper",
      "gem1_aper", "sdio0_aper", "sdio1_aper",
      "spi0_aper", "spi1_aper", "can0_aper", "can1_aper",
      "i2c0_aper", "i2c1_aper", "uart0_aper", "uart1_aper",
      "gpio_aper", "lqspi_aper", "smc_aper", "swdt",
      "dbg_trc", "dbg_apb";
    reg = <0x100 0x100>;
   };

   rstc: rstc@200 {
    compatible = "xlnx,zynq-reset";
    reg = <0x200 0x48>;
    #reset-cells = <1>;
    syscon = <&slcr>;
   };

   pinctrl0: pinctrl@700 {
    compatible = "xlnx,pinctrl-zynq";
    reg = <0x700 0x200>;
    syscon = <&slcr>;
   };
  };

  dmac_s: dmac@f8003000 {
   compatible = "arm,pl330", "arm,primecell";
   reg = <0xf8003000 0x1000>;
   interrupt-parent = <&intc>;
   interrupt-names = "abort", "dma0", "dma1", "dma2", "dma3",
    "dma4", "dma5", "dma6", "dma7";
   interrupts = <0 13 4>,
                <0 14 4>, <0 15 4>,
                <0 16 4>, <0 17 4>,
                <0 40 4>, <0 41 4>,
                <0 42 4>, <0 43 4>;
   #dma-cells = <1>;
   #dma-channels = <8>;
   #dma-requests = <4>;
   clocks = <&clkc 27>;
   clock-names = "apb_pclk";
  };

  devcfg: devcfg@f8007000 {
   compatible = "xlnx,zynq-devcfg-1.0";
   interrupt-parent = <&intc>;
   interrupts = <0 8 4>;
   reg = <0xf8007000 0x100>;
   clocks = <&clkc 12>, <&clkc 15>, <&clkc 16>, <&clkc 17>, <&clkc 18>;
   clock-names = "ref_clk", "fclk0", "fclk1", "fclk2", "fclk3";
   syscon = <&slcr>;
  };

  efuse: efuse@f800d000 {
   compatible = "xlnx,zynq-efuse";
   reg = <0xf800d000 0x20>;
  };

  global_timer: timer@f8f00200 {
   compatible = "arm,cortex-a9-global-timer";
   reg = <0xf8f00200 0x20>;
   interrupts = <1 11 0x301>;
   interrupt-parent = <&intc>;
   clocks = <&clkc 4>;
  };

  ttc0: timer@f8001000 {
   interrupt-parent = <&intc>;
   interrupts = <0 10 4>, <0 11 4>, <0 12 4>;
   compatible = "cdns,ttc";
   clocks = <&clkc 6>;
   reg = <0xF8001000 0x1000>;
  };

  ttc1: timer@f8002000 {
   interrupt-parent = <&intc>;
   interrupts = <0 37 4>, <0 38 4>, <0 39 4>;
   compatible = "cdns,ttc";
   clocks = <&clkc 6>;
   reg = <0xF8002000 0x1000>;
  };

  scutimer: timer@f8f00600 {
   interrupt-parent = <&intc>;
   interrupts = <1 13 0x301>;
   compatible = "arm,cortex-a9-twd-timer";
   reg = <0xf8f00600 0x20>;
   clocks = <&clkc 4>;
  };

  usb0: usb@e0002000 {
   compatible = "xlnx,zynq-usb-2.20a", "chipidea,usb2";
   status = "disabled";
   clocks = <&clkc 28>;
   interrupt-parent = <&intc>;
   interrupts = <0 21 4>;
   reg = <0xe0002000 0x1000>;
   phy_type = "ulpi";
  };

  usb1: usb@e0003000 {
   compatible = "xlnx,zynq-usb-2.20a", "chipidea,usb2";
   status = "disabled";
   clocks = <&clkc 29>;
   interrupt-parent = <&intc>;
   interrupts = <0 44 4>;
   reg = <0xe0003000 0x1000>;
   phy_type = "ulpi";
  };

  watchdog0: watchdog@f8005000 {
   clocks = <&clkc 45>;
   compatible = "cdns,wdt-r1p2";
   interrupt-parent = <&intc>;
   interrupts = <0 9 1>;
   reg = <0xf8005000 0x1000>;
   timeout-sec = <10>;
  };

  etb@f8801000 {
   compatible = "arm,coresight-etb10", "arm,primecell";
   reg = <0xf8801000 0x1000>;
   clocks = <&clkc 27>, <&clkc 46>, <&clkc 47>;
   clock-names = "apb_pclk", "dbg_trc", "dbg_apb";
   in-ports {
    port {
     etb_in_port: endpoint {
      remote-endpoint = <&replicator_out_port1>;
     };
    };
   };
  };

  tpiu@f8803000 {
   compatible = "arm,coresight-tpiu", "arm,primecell";
   reg = <0xf8803000 0x1000>;
   clocks = <&clkc 27>, <&clkc 46>, <&clkc 47>;
   clock-names = "apb_pclk", "dbg_trc", "dbg_apb";
   in-ports {
    port {
     tpiu_in_port: endpoint {
      remote-endpoint = <&replicator_out_port0>;
     };
    };
   };
  };

  funnel@f8804000 {
   compatible = "arm,coresight-static-funnel", "arm,primecell";
   reg = <0xf8804000 0x1000>;
   clocks = <&clkc 27>, <&clkc 46>, <&clkc 47>;
   clock-names = "apb_pclk", "dbg_trc", "dbg_apb";


   out-ports {
    port {
     funnel_out_port: endpoint {
      remote-endpoint =
       <&replicator_in_port0>;
     };
    };
   };

   in-ports {
    #address-cells = <1>;
    #size-cells = <0>;


    port@0 {
     reg = <0>;
     funnel0_in_port0: endpoint {
      remote-endpoint = <&ptm0_out_port>;
     };
    };

    port@1 {
     reg = <1>;
     funnel0_in_port1: endpoint {
      remote-endpoint = <&ptm1_out_port>;
     };
    };

    port@2 {
     reg = <2>;
     funnel0_in_port2: endpoint {
     };
    };

   };
  };

  ptm@f889c000 {
   compatible = "arm,coresight-etm3x", "arm,primecell";
   reg = <0xf889c000 0x1000>;
   clocks = <&clkc 27>, <&clkc 46>, <&clkc 47>;
   clock-names = "apb_pclk", "dbg_trc", "dbg_apb";
   cpu = <&cpu0>;
   out-ports {
    port {
     ptm0_out_port: endpoint {
      remote-endpoint = <&funnel0_in_port0>;
     };
    };
   };
  };

  ptm@f889d000 {
   compatible = "arm,coresight-etm3x", "arm,primecell";
   reg = <0xf889d000 0x1000>;
   clocks = <&clkc 27>, <&clkc 46>, <&clkc 47>;
   clock-names = "apb_pclk", "dbg_trc", "dbg_apb";
   cpu = <&cpu1>;
   out-ports {
    port {
     ptm1_out_port: endpoint {
      remote-endpoint = <&funnel0_in_port1>;
     };
    };
   };
  };
 };
};
# 10 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/system-top.dts" 2
# 1 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/zedboard.dtsi" 1
/ {
 model = "Zynq Zed Development Board";
 compatible = "xlnx,zynq-zed", "xlnx,zynq-7000";

 usb_phy0: phy0@e0002000 {
  compatible = "ulpi-phy";
  #phy-cells = <0>;
  reg = <0xe0002000 0x1000>;
  view-port = <0x0170>;
  drv-vbus;
 };
};

&clkc {
 ps-clk-frequency = <33333333>;
};

&gem0 {
 phy-handle = <&ethernet_phy>;
 ethernet_phy: ethernet-phy@0 {
  reg = <0>;
  device_type = "ethernet-phy";
 };
};

&qspi {
 u-boot,dm-pre-reloc;
 is-dual = <0>;
 num-cs = <1>;
 flash@0 {
  compatible = "n25q128a11", "jedec,spi-nor";
  reg = <0x0>;
  spi-tx-bus-width = <1>;
  spi-rx-bus-width = <4>;
  spi-max-frequency = <50000000>;
  #address-cells = <1>;
  #size-cells = <1>;
  partition@qspi-fsbl-uboot {
   label = "qspi-fsbl-uboot";
   reg = <0x0 0x100000>;
  };
  partition@qspi-1 {
   label = "qspi-linux";
   reg = <0x100000 0x500000>;
  };
  partition@qspi-device-tree {
   label = "qspi-device-tree";
   reg = <0x600000 0x20000>;
  };
  partition@qspi-rootfs {
   label = "qspi-rootfs";
   reg = <0x620000 0x5E0000>;
  };
  partition@qspi-bitstream {
   label = "qspi-bitstream";
   reg = <0xC00000 0x400000>;
  };
 };
};

&sdhci0 {
 u-boot,dm-pre-reloc;
};

&uart1 {
 u-boot,dm-pre-reloc;
};

&usb0 {
 dr_mode = "host";
 usb-phy = <&usb_phy0>;
};
# 11 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/system-top.dts" 2
# 1 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/pl.dtsi" 1







/ {
 amba_pl: amba_pl {
  #address-cells = <1>;
  #size-cells = <1>;
  compatible = "simple-bus";
  ranges ;
  axi_dma_0: dma@40400000 {
   #dma-cells = <1>;
   clock-names = "s_axi_lite_aclk", "m_axi_sg_aclk", "m_axi_mm2s_aclk", "m_axi_s2mm_aclk";
   clocks = <&clkc 15>, <&clkc 15>, <&clkc 15>, <&clkc 15>;
   compatible = "xlnx,axi-dma-7.1", "xlnx,axi-dma-1.00.a";
   interrupt-names = "mm2s_introut", "s2mm_introut";
   interrupt-parent = <&intc>;
   interrupts = <0 29 4 0 30 4>;
   reg = <0x40400000 0x10000>;
   xlnx,addrwidth = <0x20>;
   xlnx,include-sg ;
   xlnx,sg-length-width = <0xe>;
   dma-channel@40400000 {
    compatible = "xlnx,axi-dma-mm2s-channel";
    dma-channels = <0x1>;
    interrupts = <0 29 4>;
    xlnx,datawidth = <0x20>;
    xlnx,device-id = <0x0>;
   };
   dma-channel@40400030 {
    compatible = "xlnx,axi-dma-s2mm-channel";
    dma-channels = <0x1>;
    interrupts = <0 30 4>;
    xlnx,datawidth = <0x20>;
    xlnx,device-id = <0x0>;
   };
  };
 };
};
# 12 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/system-top.dts" 2
# 1 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/pcw.dtsi" 1







/ {
 cpus {
  cpu@0 {
   operating-points = <666666 1000000 333333 1000000>;
  };
 };
};
&gem0 {
 phy-mode = "rgmii-id";
 status = "okay";
 xlnx,ptp-enet-clock = <0x69f6bcb>;
};
&gpio0 {
 emio-gpio-width = <64>;
 gpio-mask-high = <0x0>;
 gpio-mask-low = <0x5600>;
};
&intc {
 num_cpus = <2>;
 num_interrupts = <96>;
};
&qspi {
 is-dual = <0>;
 num-cs = <1>;
 spi-rx-bus-width = <4>;
 spi-tx-bus-width = <4>;
 status = "okay";
};
&sdhci0 {
 status = "okay";
 xlnx,has-cd = <0x1>;
 xlnx,has-power = <0x0>;
 xlnx,has-wp = <0x1>;
};
&uart1 {
 cts-override ;
 device_type = "serial";
 port-number = <0>;
 status = "okay";
};
&usb0 {
 phy_type = "ulpi";
 status = "okay";
};
&clkc {
 fclk-enable = <0x1>;
 ps-clk-frequency = <33333333>;
};
# 13 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/system-top.dts" 2
/ {
 chosen {
  bootargs = "earlycon";
  stdout-path = "serial0:115200n8";
 };
 aliases {
  ethernet0 = &gem0;
  serial0 = &uart1;
  spi0 = &qspi;
 };
 memory {
  device_type = "memory";
  reg = <0x0 0x20000000>;
 };
};
# 2 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/system.dts" 2
# 1 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/zynq-pl-remoteport.dtsi" 1
# 29 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/zynq-pl-remoteport.dtsi"
&slcr {

 #gpio-cells = <1>;
 gpio-controller;
};


/ {






 amba_pl {
  cosim_rp_0: cosim@0 {
   compatible = "remote-port";
   sync = <1>;
   chrdev-id = "pl-rp";
  };

  m_axi_gp0: rp_m_axi_gp0@40000000 {
   compatible = "remote-port-memory-master";
   remote-ports = < &cosim_rp_0 7 >;
   reg = < 0x40000000 0x40000000 >;
  };

  m_axi_gp1: rp_m_axi_gp1@80000000 {
   compatible = "remote-port-memory-master";
   remote-ports = < &cosim_rp_0 8 >;
   reg = < 0x80000000 0x40000000 >;
  };

  s_axi_gp0: rp_s_axi_gp0@0 {
   compatible = "remote-port-memory-slave";
   remote-ports = < &cosim_rp_0 0 >;
  };
  s_axi_gp1: rp_s_axi_gp1@0 {
   compatible = "remote-port-memory-slave";
   remote-ports = < &cosim_rp_0 1 >;
  };
  afi_0: rp_afi0@0 {
   compatible = "remote-port-memory-slave";
   remote-ports = < &cosim_rp_0 2 >;
  };
  afi_1: rp_afi1@0 {
   compatible = "remote-port-memory-slave";
   remote-ports = < &cosim_rp_0 3 >;
  };
  afi_2: rp_afi2@0 {
   compatible = "remote-port-memory-slave";
   remote-ports = < &cosim_rp_0 4 >;
  };
  afi_3: rp_afi3@0 {
   compatible = "remote-port-memory-slave";
   remote-ports = < &cosim_rp_0 5 >;
  };
  acp: rp_acp0@0 {
   compatible = "remote-port-memory-slave";
   remote-ports = < &cosim_rp_0 6 >;
  };

  wires_in: rp_wires_in@0 {
   compatible = "remote-port-gpio";
   remote-ports = < &cosim_rp_0 9 >;
   num-gpios = < 16 >;



   interrupt-parent = < &intc >;
   interrupts = <
           0x0 29 0x4
           0x0 30 0x4
           0x0 31 0x4
           0x0 32 0x4
           0x0 33 0x4
           0x0 34 0x4
           0x0 35 0x4
           0x0 36 0x4

           0x0 52 0x4
           0x0 53 0x4
           0x0 54 0x4
           0x0 55 0x4
           0x0 56 0x4
           0x0 57 0x4
           0x0 58 0x4
           0x0 59 0x4
         >;
  };

  wires_out: rp_wires_out@0 {
   compatible = "remote-port-gpio";
   remote-ports = < &cosim_rp_0 10 >;
   num-gpios = <17>;
   gpios = <

      &slcr 2 &slcr 3 &slcr 4 &slcr 5
      &slcr 6 &slcr 7 &slcr 8 &slcr 9
      &slcr 10 &slcr 11 &slcr 12 &slcr 13
      &slcr 14 &slcr 15 &slcr 16 &slcr 17
      &slcr 18
    >;
  };

  rp_cosim_intr_pstopl: rp_cosim_intr_pstopl@0 {
   #interrupt-cells = <3>;
   interrupt-controller;
   compatible = "remote-port-gpio";
   remote-ports = <&cosim_rp_0 11>;



   num-gpios = <96>;
   cell-offset-irq-num = <1>;
  };


  rp_cosim_reserved: rp_cosim_reserved@0{
   compatible = "remote-port-memory-master";
   remote-ports = <&cosim_rp_0 12>;
   reg = <0xFE000000 0x100000>;
  };
 };
};

&can1 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 0 4>, <0 0 0 &intc 0 51 4>;
};

&uart1 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 1 4>, <0 0 0 &intc 0 50 4>;
};

&spi1 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 2 4>, <0 0 0 &intc 0 49 4>;
};

&i2c1 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 3 4>, <0 0 0 &intc 0 48 4>;
};

&sdhci1 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 4 4>, <0 0 0 &intc 0 47 4>;
};

&gem1 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 6 4>, <0 0 0 &intc 0 45 4>;
};

&usb1 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 7 4>, <0 0 0 &intc 0 44 4>;
};

&can0 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 8 4>, <0 0 0 &intc 0 28 4>;
};

&spi0 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 10 4>, <0 0 0 &intc 0 26 4>;
};

&i2c0 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 11 4>, <0 0 0 &intc 0 25 4>;
};

&sdhci0 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 12 4>, <0 0 0 &intc 0 24 4>;
};

&gem0 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 14 4>, <0 0 0 &intc 0 22 4>;
};

&usb0 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 15 4>, <0 0 0 &intc 0 21 4>;
};

&gpio0 {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 16 4>, <0 0 0 &intc 0 20 4>;
};

&qspi {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 18 4>, <0 0 0 &intc 0 19 4>;
};

&smcc {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 19 4>, <0 0 0 &intc 0 18 4>;
};

&dmac_s {
 #interrupt-cells = <1>;
 interrupt-map-mask = <0 0 0 0>;
 interrupt-map = <0 0 0 &rp_cosim_intr_pstopl 0 28 4>, <0 0 0 &intc 0 13 4>,
     <0 0 0 &rp_cosim_intr_pstopl 0 20 4>, <0 0 0 &intc 0 14 4>,
     <0 0 0 &rp_cosim_intr_pstopl 0 21 4>, <0 0 0 &intc 0 15 4>,
     <0 0 0 &rp_cosim_intr_pstopl 0 22 4>, <0 0 0 &intc 0 16 4>,
     <0 0 0 &rp_cosim_intr_pstopl 0 23 4>, <0 0 0 &intc 0 17 4>,
     <0 0 0 &rp_cosim_intr_pstopl 0 24 4>, <0 0 0 &intc 0 40 4>,
     <0 0 0 &rp_cosim_intr_pstopl 0 25 4>, <0 0 0 &intc 0 41 4>,
     <0 0 0 &rp_cosim_intr_pstopl 0 26 4>, <0 0 0 &intc 0 42 4>,
     <0 0 0 &rp_cosim_intr_pstopl 0 27 4>, <0 0 0 &intc 0 43 4>;
};
# 3 "/home/alisoukarieh/Documents/ProjetCodesign/build/spectrum_analyzer_avnet_zedboard/xsim-hw_emu/dts/system.dts" 2
