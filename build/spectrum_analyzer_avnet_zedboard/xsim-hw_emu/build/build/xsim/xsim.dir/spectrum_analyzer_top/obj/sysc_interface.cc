#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 
#include "xsim.dir/spectrum_analyzer_top/obj/sysc_interface.h"
#include <map>
#include <list>


extern "C" { std::vector<void*> *_glb_hdl_sc_channel_map; } 



extern "C"
    void call_HDL_SC_WRITE_bv_2(unsigned int sc_net_index, char* pval)
    {
          ((xsim_sc_channel<2, sc_dt::sc_bv<2> >*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(pval);
    } 


extern "C"
    void call_HDL_SC_WRITE_bv_3(unsigned int sc_net_index, char* pval)
    {
          ((xsim_sc_channel<3, sc_dt::sc_bv<3> >*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(pval);
    } 


extern "C"
    void call_HDL_SC_WRITE_bv_4(unsigned int sc_net_index, char* pval)
    {
          ((xsim_sc_channel<4, sc_dt::sc_bv<4> >*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(pval);
    } 


extern "C"
    void call_HDL_SC_WRITE_bv_6(unsigned int sc_net_index, char* pval)
    {
          ((xsim_sc_channel<6, sc_dt::sc_bv<6> >*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(pval);
    } 


extern "C"
    void call_HDL_SC_WRITE_bv_8(unsigned int sc_net_index, char* pval)
    {
          ((xsim_sc_channel<8, sc_dt::sc_bv<8> >*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(pval);
    } 


extern "C"
    void call_HDL_SC_WRITE_bv_12(unsigned int sc_net_index, char* pval)
    {
          ((xsim_sc_channel<12, sc_dt::sc_bv<12> >*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(pval);
    } 


extern "C"
    void call_HDL_SC_WRITE_bv_15(unsigned int sc_net_index, char* pval)
    {
          ((xsim_sc_channel<15, sc_dt::sc_bv<15> >*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(pval);
    } 


extern "C"
    void call_HDL_SC_WRITE_bv_32(unsigned int sc_net_index, char* pval)
    {
          ((xsim_sc_channel<32, sc_dt::sc_bv<32> >*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(pval);
    } 


extern "C"
    void call_HDL_SC_WRITE_bv_54(unsigned int sc_net_index, char* pval)
    {
          ((xsim_sc_channel<54, sc_dt::sc_bv<54> >*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(pval);
    } 


extern "C"
    void call_HDL_SC_WRITE_bv_64(unsigned int sc_net_index, char* pval)
    {
          ((xsim_sc_channel<64, sc_dt::sc_bv<64> >*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(pval);
    } 


extern "C"
    void call_HDL_SC_WRITE_int(unsigned int sc_net_index, char* pval)
    {
          int val = *((int*)(pval));
          ((xsim_sc_channel<0, int>*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(val);
    } 



extern "C"
    void call_HDL_SC_WRITE_bit(unsigned int sc_net_index, char* pval)
    {
            sc_dt::sc_bit val  =  (sc_dt::sc_bit)((*((int*)(pval)) & 0x1));
          ((xsim_sc_channel<0, sc_dt::sc_bit>*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(val);
    } 



extern "C"
    void call_HDL_SC_WRITE_logic(unsigned int sc_net_index, char* pval)
    {
          sc_dt::sc_logic val  =  (sc_dt::sc_logic_value_t) (((*((int*)(pval)+1) & 0x1) << 1) | (*((int*)(pval)) & 0x1));
          ((xsim_sc_channel<0, sc_dt::sc_logic>*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(val);
    } 



extern "C"
    void call_HDL_SC_WRITE_bool(unsigned int sc_net_index, char* pval)
    {
          bool val = *((bool*)(pval));
          ((xsim_sc_channel<0, bool>*)(*_glb_hdl_sc_channel_map)[sc_net_index])->update_from_hdl(val);
    } 



extern "C"
    void implicit_HDL_SCinstantiate()
    {
        _glb_hdl_sc_channel_map = new std::vector<void*> ();
        sc_inst_1 = new design_1_processing_system7_0_0(".spectrum_analyzer_top.bd_inst.design_1_i.processing_system7_0");
        sc_inst_1->xsim_set_dbg_index(34);
        xsim_sc_channel<0, bool > *p_1_TTC0_WAVE0_OUT = new xsim_sc_channel<0, bool >();
        sc_inst_1->TTC0_WAVE0_OUT.bind(*p_1_TTC0_WAVE0_OUT);
        p_1_TTC0_WAVE0_OUT->set_sv_netview_offsetfromdp(11734824);
        xsim_sc_channel<0, bool > *p_1_TTC0_WAVE1_OUT = new xsim_sc_channel<0, bool >();
        sc_inst_1->TTC0_WAVE1_OUT.bind(*p_1_TTC0_WAVE1_OUT);
        p_1_TTC0_WAVE1_OUT->set_sv_netview_offsetfromdp(11734880);
        xsim_sc_channel<0, bool > *p_1_TTC0_WAVE2_OUT = new xsim_sc_channel<0, bool >();
        sc_inst_1->TTC0_WAVE2_OUT.bind(*p_1_TTC0_WAVE2_OUT);
        p_1_TTC0_WAVE2_OUT->set_sv_netview_offsetfromdp(11734936);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_USB0_PORT_INDCTL = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->USB0_PORT_INDCTL.bind(*p_1_USB0_PORT_INDCTL);
        p_1_USB0_PORT_INDCTL->set_sv_netview_offsetfromdp(11734992);
        xsim_sc_channel<0, bool > *p_1_USB0_VBUS_PWRSELECT = new xsim_sc_channel<0, bool >();
        sc_inst_1->USB0_VBUS_PWRSELECT.bind(*p_1_USB0_VBUS_PWRSELECT);
        p_1_USB0_VBUS_PWRSELECT->set_sv_netview_offsetfromdp(11735048);
        xsim_sc_channel<0, bool > *p_1_USB0_VBUS_PWRFAULT = new xsim_sc_channel<0, bool >();
        sc_inst_1->USB0_VBUS_PWRFAULT.bind(*p_1_USB0_VBUS_PWRFAULT);
        (*_glb_hdl_sc_channel_map).push_back(p_1_USB0_VBUS_PWRFAULT);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_ARVALID = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_ARVALID.bind(*p_1_M_AXI_GP0_ARVALID);
        p_1_M_AXI_GP0_ARVALID->set_sv_netview_offsetfromdp(11735160);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_AWVALID = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_AWVALID.bind(*p_1_M_AXI_GP0_AWVALID);
        p_1_M_AXI_GP0_AWVALID->set_sv_netview_offsetfromdp(11735216);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_BREADY = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_BREADY.bind(*p_1_M_AXI_GP0_BREADY);
        p_1_M_AXI_GP0_BREADY->set_sv_netview_offsetfromdp(11735272);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_RREADY = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_RREADY.bind(*p_1_M_AXI_GP0_RREADY);
        p_1_M_AXI_GP0_RREADY->set_sv_netview_offsetfromdp(11735328);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_WLAST = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_WLAST.bind(*p_1_M_AXI_GP0_WLAST);
        p_1_M_AXI_GP0_WLAST->set_sv_netview_offsetfromdp(11735384);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_WVALID = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_WVALID.bind(*p_1_M_AXI_GP0_WVALID);
        p_1_M_AXI_GP0_WVALID->set_sv_netview_offsetfromdp(11735440);
        xsim_sc_channel<12, sc_dt::sc_bv<12> > *p_1_M_AXI_GP0_ARID = new xsim_sc_channel<12, sc_dt::sc_bv<12> >();
        sc_inst_1->M_AXI_GP0_ARID.bind(*p_1_M_AXI_GP0_ARID);
        p_1_M_AXI_GP0_ARID->set_sv_netview_offsetfromdp(11735496);
        xsim_sc_channel<12, sc_dt::sc_bv<12> > *p_1_M_AXI_GP0_AWID = new xsim_sc_channel<12, sc_dt::sc_bv<12> >();
        sc_inst_1->M_AXI_GP0_AWID.bind(*p_1_M_AXI_GP0_AWID);
        p_1_M_AXI_GP0_AWID->set_sv_netview_offsetfromdp(11735552);
        xsim_sc_channel<12, sc_dt::sc_bv<12> > *p_1_M_AXI_GP0_WID = new xsim_sc_channel<12, sc_dt::sc_bv<12> >();
        sc_inst_1->M_AXI_GP0_WID.bind(*p_1_M_AXI_GP0_WID);
        p_1_M_AXI_GP0_WID->set_sv_netview_offsetfromdp(11735608);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_M_AXI_GP0_ARBURST = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->M_AXI_GP0_ARBURST.bind(*p_1_M_AXI_GP0_ARBURST);
        p_1_M_AXI_GP0_ARBURST->set_sv_netview_offsetfromdp(11735664);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_M_AXI_GP0_ARLOCK = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->M_AXI_GP0_ARLOCK.bind(*p_1_M_AXI_GP0_ARLOCK);
        p_1_M_AXI_GP0_ARLOCK->set_sv_netview_offsetfromdp(11735720);
        xsim_sc_channel<3, sc_dt::sc_bv<3> > *p_1_M_AXI_GP0_ARSIZE = new xsim_sc_channel<3, sc_dt::sc_bv<3> >();
        sc_inst_1->M_AXI_GP0_ARSIZE.bind(*p_1_M_AXI_GP0_ARSIZE);
        p_1_M_AXI_GP0_ARSIZE->set_sv_netview_offsetfromdp(11735776);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_M_AXI_GP0_AWBURST = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->M_AXI_GP0_AWBURST.bind(*p_1_M_AXI_GP0_AWBURST);
        p_1_M_AXI_GP0_AWBURST->set_sv_netview_offsetfromdp(11735832);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_M_AXI_GP0_AWLOCK = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->M_AXI_GP0_AWLOCK.bind(*p_1_M_AXI_GP0_AWLOCK);
        p_1_M_AXI_GP0_AWLOCK->set_sv_netview_offsetfromdp(11735888);
        xsim_sc_channel<3, sc_dt::sc_bv<3> > *p_1_M_AXI_GP0_AWSIZE = new xsim_sc_channel<3, sc_dt::sc_bv<3> >();
        sc_inst_1->M_AXI_GP0_AWSIZE.bind(*p_1_M_AXI_GP0_AWSIZE);
        p_1_M_AXI_GP0_AWSIZE->set_sv_netview_offsetfromdp(11735944);
        xsim_sc_channel<3, sc_dt::sc_bv<3> > *p_1_M_AXI_GP0_ARPROT = new xsim_sc_channel<3, sc_dt::sc_bv<3> >();
        sc_inst_1->M_AXI_GP0_ARPROT.bind(*p_1_M_AXI_GP0_ARPROT);
        p_1_M_AXI_GP0_ARPROT->set_sv_netview_offsetfromdp(11736000);
        xsim_sc_channel<3, sc_dt::sc_bv<3> > *p_1_M_AXI_GP0_AWPROT = new xsim_sc_channel<3, sc_dt::sc_bv<3> >();
        sc_inst_1->M_AXI_GP0_AWPROT.bind(*p_1_M_AXI_GP0_AWPROT);
        p_1_M_AXI_GP0_AWPROT->set_sv_netview_offsetfromdp(11736056);
        xsim_sc_channel<32, sc_dt::sc_bv<32> > *p_1_M_AXI_GP0_ARADDR = new xsim_sc_channel<32, sc_dt::sc_bv<32> >();
        sc_inst_1->M_AXI_GP0_ARADDR.bind(*p_1_M_AXI_GP0_ARADDR);
        p_1_M_AXI_GP0_ARADDR->set_sv_netview_offsetfromdp(11736112);
        xsim_sc_channel<32, sc_dt::sc_bv<32> > *p_1_M_AXI_GP0_AWADDR = new xsim_sc_channel<32, sc_dt::sc_bv<32> >();
        sc_inst_1->M_AXI_GP0_AWADDR.bind(*p_1_M_AXI_GP0_AWADDR);
        p_1_M_AXI_GP0_AWADDR->set_sv_netview_offsetfromdp(11736168);
        xsim_sc_channel<32, sc_dt::sc_bv<32> > *p_1_M_AXI_GP0_WDATA = new xsim_sc_channel<32, sc_dt::sc_bv<32> >();
        sc_inst_1->M_AXI_GP0_WDATA.bind(*p_1_M_AXI_GP0_WDATA);
        p_1_M_AXI_GP0_WDATA->set_sv_netview_offsetfromdp(11736224);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_M_AXI_GP0_ARCACHE = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->M_AXI_GP0_ARCACHE.bind(*p_1_M_AXI_GP0_ARCACHE);
        p_1_M_AXI_GP0_ARCACHE->set_sv_netview_offsetfromdp(11736280);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_M_AXI_GP0_ARLEN = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->M_AXI_GP0_ARLEN.bind(*p_1_M_AXI_GP0_ARLEN);
        p_1_M_AXI_GP0_ARLEN->set_sv_netview_offsetfromdp(11736336);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_M_AXI_GP0_ARQOS = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->M_AXI_GP0_ARQOS.bind(*p_1_M_AXI_GP0_ARQOS);
        p_1_M_AXI_GP0_ARQOS->set_sv_netview_offsetfromdp(11736392);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_M_AXI_GP0_AWCACHE = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->M_AXI_GP0_AWCACHE.bind(*p_1_M_AXI_GP0_AWCACHE);
        p_1_M_AXI_GP0_AWCACHE->set_sv_netview_offsetfromdp(11736448);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_M_AXI_GP0_AWLEN = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->M_AXI_GP0_AWLEN.bind(*p_1_M_AXI_GP0_AWLEN);
        p_1_M_AXI_GP0_AWLEN->set_sv_netview_offsetfromdp(11736504);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_M_AXI_GP0_AWQOS = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->M_AXI_GP0_AWQOS.bind(*p_1_M_AXI_GP0_AWQOS);
        p_1_M_AXI_GP0_AWQOS->set_sv_netview_offsetfromdp(11736560);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_M_AXI_GP0_WSTRB = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->M_AXI_GP0_WSTRB.bind(*p_1_M_AXI_GP0_WSTRB);
        p_1_M_AXI_GP0_WSTRB->set_sv_netview_offsetfromdp(11736616);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_ACLK = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_ACLK.bind(*p_1_M_AXI_GP0_ACLK);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_ACLK);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_ARREADY = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_ARREADY.bind(*p_1_M_AXI_GP0_ARREADY);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_ARREADY);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_AWREADY = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_AWREADY.bind(*p_1_M_AXI_GP0_AWREADY);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_AWREADY);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_BVALID = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_BVALID.bind(*p_1_M_AXI_GP0_BVALID);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_BVALID);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_RLAST = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_RLAST.bind(*p_1_M_AXI_GP0_RLAST);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_RLAST);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_RVALID = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_RVALID.bind(*p_1_M_AXI_GP0_RVALID);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_RVALID);
        xsim_sc_channel<0, bool > *p_1_M_AXI_GP0_WREADY = new xsim_sc_channel<0, bool >();
        sc_inst_1->M_AXI_GP0_WREADY.bind(*p_1_M_AXI_GP0_WREADY);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_WREADY);
        xsim_sc_channel<12, sc_dt::sc_bv<12> > *p_1_M_AXI_GP0_BID = new xsim_sc_channel<12, sc_dt::sc_bv<12> >();
        sc_inst_1->M_AXI_GP0_BID.bind(*p_1_M_AXI_GP0_BID);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_BID);
        xsim_sc_channel<12, sc_dt::sc_bv<12> > *p_1_M_AXI_GP0_RID = new xsim_sc_channel<12, sc_dt::sc_bv<12> >();
        sc_inst_1->M_AXI_GP0_RID.bind(*p_1_M_AXI_GP0_RID);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_RID);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_M_AXI_GP0_BRESP = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->M_AXI_GP0_BRESP.bind(*p_1_M_AXI_GP0_BRESP);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_BRESP);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_M_AXI_GP0_RRESP = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->M_AXI_GP0_RRESP.bind(*p_1_M_AXI_GP0_RRESP);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_RRESP);
        xsim_sc_channel<32, sc_dt::sc_bv<32> > *p_1_M_AXI_GP0_RDATA = new xsim_sc_channel<32, sc_dt::sc_bv<32> >();
        sc_inst_1->M_AXI_GP0_RDATA.bind(*p_1_M_AXI_GP0_RDATA);
        (*_glb_hdl_sc_channel_map).push_back(p_1_M_AXI_GP0_RDATA);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_ARREADY = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_ARREADY.bind(*p_1_S_AXI_HP0_ARREADY);
        p_1_S_AXI_HP0_ARREADY->set_sv_netview_offsetfromdp(11737344);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_AWREADY = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_AWREADY.bind(*p_1_S_AXI_HP0_AWREADY);
        p_1_S_AXI_HP0_AWREADY->set_sv_netview_offsetfromdp(11737400);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_BVALID = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_BVALID.bind(*p_1_S_AXI_HP0_BVALID);
        p_1_S_AXI_HP0_BVALID->set_sv_netview_offsetfromdp(11737456);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_RLAST = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_RLAST.bind(*p_1_S_AXI_HP0_RLAST);
        p_1_S_AXI_HP0_RLAST->set_sv_netview_offsetfromdp(11737512);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_RVALID = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_RVALID.bind(*p_1_S_AXI_HP0_RVALID);
        p_1_S_AXI_HP0_RVALID->set_sv_netview_offsetfromdp(11737568);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_WREADY = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_WREADY.bind(*p_1_S_AXI_HP0_WREADY);
        p_1_S_AXI_HP0_WREADY->set_sv_netview_offsetfromdp(11737624);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_S_AXI_HP0_BRESP = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->S_AXI_HP0_BRESP.bind(*p_1_S_AXI_HP0_BRESP);
        p_1_S_AXI_HP0_BRESP->set_sv_netview_offsetfromdp(11737680);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_S_AXI_HP0_RRESP = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->S_AXI_HP0_RRESP.bind(*p_1_S_AXI_HP0_RRESP);
        p_1_S_AXI_HP0_RRESP->set_sv_netview_offsetfromdp(11737736);
        xsim_sc_channel<6, sc_dt::sc_bv<6> > *p_1_S_AXI_HP0_BID = new xsim_sc_channel<6, sc_dt::sc_bv<6> >();
        sc_inst_1->S_AXI_HP0_BID.bind(*p_1_S_AXI_HP0_BID);
        p_1_S_AXI_HP0_BID->set_sv_netview_offsetfromdp(11737792);
        xsim_sc_channel<6, sc_dt::sc_bv<6> > *p_1_S_AXI_HP0_RID = new xsim_sc_channel<6, sc_dt::sc_bv<6> >();
        sc_inst_1->S_AXI_HP0_RID.bind(*p_1_S_AXI_HP0_RID);
        p_1_S_AXI_HP0_RID->set_sv_netview_offsetfromdp(11737848);
        xsim_sc_channel<64, sc_dt::sc_bv<64> > *p_1_S_AXI_HP0_RDATA = new xsim_sc_channel<64, sc_dt::sc_bv<64> >();
        sc_inst_1->S_AXI_HP0_RDATA.bind(*p_1_S_AXI_HP0_RDATA);
        p_1_S_AXI_HP0_RDATA->set_sv_netview_offsetfromdp(11737904);
        xsim_sc_channel<8, sc_dt::sc_bv<8> > *p_1_S_AXI_HP0_RCOUNT = new xsim_sc_channel<8, sc_dt::sc_bv<8> >();
        sc_inst_1->S_AXI_HP0_RCOUNT.bind(*p_1_S_AXI_HP0_RCOUNT);
        p_1_S_AXI_HP0_RCOUNT->set_sv_netview_offsetfromdp(11737960);
        xsim_sc_channel<8, sc_dt::sc_bv<8> > *p_1_S_AXI_HP0_WCOUNT = new xsim_sc_channel<8, sc_dt::sc_bv<8> >();
        sc_inst_1->S_AXI_HP0_WCOUNT.bind(*p_1_S_AXI_HP0_WCOUNT);
        p_1_S_AXI_HP0_WCOUNT->set_sv_netview_offsetfromdp(11738016);
        xsim_sc_channel<3, sc_dt::sc_bv<3> > *p_1_S_AXI_HP0_RACOUNT = new xsim_sc_channel<3, sc_dt::sc_bv<3> >();
        sc_inst_1->S_AXI_HP0_RACOUNT.bind(*p_1_S_AXI_HP0_RACOUNT);
        p_1_S_AXI_HP0_RACOUNT->set_sv_netview_offsetfromdp(11738072);
        xsim_sc_channel<6, sc_dt::sc_bv<6> > *p_1_S_AXI_HP0_WACOUNT = new xsim_sc_channel<6, sc_dt::sc_bv<6> >();
        sc_inst_1->S_AXI_HP0_WACOUNT.bind(*p_1_S_AXI_HP0_WACOUNT);
        p_1_S_AXI_HP0_WACOUNT->set_sv_netview_offsetfromdp(11738128);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_ACLK = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_ACLK.bind(*p_1_S_AXI_HP0_ACLK);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ACLK);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_ARVALID = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_ARVALID.bind(*p_1_S_AXI_HP0_ARVALID);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ARVALID);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_AWVALID = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_AWVALID.bind(*p_1_S_AXI_HP0_AWVALID);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_AWVALID);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_BREADY = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_BREADY.bind(*p_1_S_AXI_HP0_BREADY);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_BREADY);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_RDISSUECAP1_EN = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_RDISSUECAP1_EN.bind(*p_1_S_AXI_HP0_RDISSUECAP1_EN);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_RDISSUECAP1_EN);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_RREADY = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_RREADY.bind(*p_1_S_AXI_HP0_RREADY);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_RREADY);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_WLAST = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_WLAST.bind(*p_1_S_AXI_HP0_WLAST);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_WLAST);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_WRISSUECAP1_EN = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_WRISSUECAP1_EN.bind(*p_1_S_AXI_HP0_WRISSUECAP1_EN);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_WRISSUECAP1_EN);
        xsim_sc_channel<0, bool > *p_1_S_AXI_HP0_WVALID = new xsim_sc_channel<0, bool >();
        sc_inst_1->S_AXI_HP0_WVALID.bind(*p_1_S_AXI_HP0_WVALID);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_WVALID);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_S_AXI_HP0_ARBURST = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->S_AXI_HP0_ARBURST.bind(*p_1_S_AXI_HP0_ARBURST);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ARBURST);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_S_AXI_HP0_ARLOCK = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->S_AXI_HP0_ARLOCK.bind(*p_1_S_AXI_HP0_ARLOCK);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ARLOCK);
        xsim_sc_channel<3, sc_dt::sc_bv<3> > *p_1_S_AXI_HP0_ARSIZE = new xsim_sc_channel<3, sc_dt::sc_bv<3> >();
        sc_inst_1->S_AXI_HP0_ARSIZE.bind(*p_1_S_AXI_HP0_ARSIZE);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ARSIZE);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_S_AXI_HP0_AWBURST = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->S_AXI_HP0_AWBURST.bind(*p_1_S_AXI_HP0_AWBURST);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_AWBURST);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_S_AXI_HP0_AWLOCK = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->S_AXI_HP0_AWLOCK.bind(*p_1_S_AXI_HP0_AWLOCK);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_AWLOCK);
        xsim_sc_channel<3, sc_dt::sc_bv<3> > *p_1_S_AXI_HP0_AWSIZE = new xsim_sc_channel<3, sc_dt::sc_bv<3> >();
        sc_inst_1->S_AXI_HP0_AWSIZE.bind(*p_1_S_AXI_HP0_AWSIZE);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_AWSIZE);
        xsim_sc_channel<3, sc_dt::sc_bv<3> > *p_1_S_AXI_HP0_ARPROT = new xsim_sc_channel<3, sc_dt::sc_bv<3> >();
        sc_inst_1->S_AXI_HP0_ARPROT.bind(*p_1_S_AXI_HP0_ARPROT);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ARPROT);
        xsim_sc_channel<3, sc_dt::sc_bv<3> > *p_1_S_AXI_HP0_AWPROT = new xsim_sc_channel<3, sc_dt::sc_bv<3> >();
        sc_inst_1->S_AXI_HP0_AWPROT.bind(*p_1_S_AXI_HP0_AWPROT);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_AWPROT);
        xsim_sc_channel<32, sc_dt::sc_bv<32> > *p_1_S_AXI_HP0_ARADDR = new xsim_sc_channel<32, sc_dt::sc_bv<32> >();
        sc_inst_1->S_AXI_HP0_ARADDR.bind(*p_1_S_AXI_HP0_ARADDR);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ARADDR);
        xsim_sc_channel<32, sc_dt::sc_bv<32> > *p_1_S_AXI_HP0_AWADDR = new xsim_sc_channel<32, sc_dt::sc_bv<32> >();
        sc_inst_1->S_AXI_HP0_AWADDR.bind(*p_1_S_AXI_HP0_AWADDR);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_AWADDR);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_S_AXI_HP0_ARCACHE = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->S_AXI_HP0_ARCACHE.bind(*p_1_S_AXI_HP0_ARCACHE);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ARCACHE);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_S_AXI_HP0_ARLEN = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->S_AXI_HP0_ARLEN.bind(*p_1_S_AXI_HP0_ARLEN);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ARLEN);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_S_AXI_HP0_ARQOS = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->S_AXI_HP0_ARQOS.bind(*p_1_S_AXI_HP0_ARQOS);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ARQOS);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_S_AXI_HP0_AWCACHE = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->S_AXI_HP0_AWCACHE.bind(*p_1_S_AXI_HP0_AWCACHE);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_AWCACHE);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_S_AXI_HP0_AWLEN = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->S_AXI_HP0_AWLEN.bind(*p_1_S_AXI_HP0_AWLEN);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_AWLEN);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_S_AXI_HP0_AWQOS = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->S_AXI_HP0_AWQOS.bind(*p_1_S_AXI_HP0_AWQOS);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_AWQOS);
        xsim_sc_channel<6, sc_dt::sc_bv<6> > *p_1_S_AXI_HP0_ARID = new xsim_sc_channel<6, sc_dt::sc_bv<6> >();
        sc_inst_1->S_AXI_HP0_ARID.bind(*p_1_S_AXI_HP0_ARID);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_ARID);
        xsim_sc_channel<6, sc_dt::sc_bv<6> > *p_1_S_AXI_HP0_AWID = new xsim_sc_channel<6, sc_dt::sc_bv<6> >();
        sc_inst_1->S_AXI_HP0_AWID.bind(*p_1_S_AXI_HP0_AWID);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_AWID);
        xsim_sc_channel<6, sc_dt::sc_bv<6> > *p_1_S_AXI_HP0_WID = new xsim_sc_channel<6, sc_dt::sc_bv<6> >();
        sc_inst_1->S_AXI_HP0_WID.bind(*p_1_S_AXI_HP0_WID);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_WID);
        xsim_sc_channel<64, sc_dt::sc_bv<64> > *p_1_S_AXI_HP0_WDATA = new xsim_sc_channel<64, sc_dt::sc_bv<64> >();
        sc_inst_1->S_AXI_HP0_WDATA.bind(*p_1_S_AXI_HP0_WDATA);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_WDATA);
        xsim_sc_channel<8, sc_dt::sc_bv<8> > *p_1_S_AXI_HP0_WSTRB = new xsim_sc_channel<8, sc_dt::sc_bv<8> >();
        sc_inst_1->S_AXI_HP0_WSTRB.bind(*p_1_S_AXI_HP0_WSTRB);
        (*_glb_hdl_sc_channel_map).push_back(p_1_S_AXI_HP0_WSTRB);
        xsim_sc_channel<2, sc_dt::sc_bv<2> > *p_1_IRQ_F2P = new xsim_sc_channel<2, sc_dt::sc_bv<2> >();
        sc_inst_1->IRQ_F2P.bind(*p_1_IRQ_F2P);
        (*_glb_hdl_sc_channel_map).push_back(p_1_IRQ_F2P);
        xsim_sc_channel<0, bool > *p_1_FCLK_CLK0 = new xsim_sc_channel<0, bool >();
        sc_inst_1->FCLK_CLK0.bind(*p_1_FCLK_CLK0);
        p_1_FCLK_CLK0->set_sv_netview_offsetfromdp(11739920);
        xsim_sc_channel<0, bool > *p_1_FCLK_RESET0_N = new xsim_sc_channel<0, bool >();
        sc_inst_1->FCLK_RESET0_N.bind(*p_1_FCLK_RESET0_N);
        p_1_FCLK_RESET0_N->set_sv_netview_offsetfromdp(11739976);
        xsim_sc_channel<54, sc_dt::sc_bv<54> > *p_1_MIO = new xsim_sc_channel<54, sc_dt::sc_bv<54> >();
        sc_inst_1->MIO.bind(*p_1_MIO);
        p_1_MIO->set_sv_netview_offsetfromdp(11740032);
        xsim_sc_channel<0, bool > *p_1_DDR_CAS_n = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_CAS_n.bind(*p_1_DDR_CAS_n);
        p_1_DDR_CAS_n->set_sv_netview_offsetfromdp(11740088);
        xsim_sc_channel<0, bool > *p_1_DDR_CKE = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_CKE.bind(*p_1_DDR_CKE);
        p_1_DDR_CKE->set_sv_netview_offsetfromdp(11740144);
        xsim_sc_channel<0, bool > *p_1_DDR_Clk_n = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_Clk_n.bind(*p_1_DDR_Clk_n);
        p_1_DDR_Clk_n->set_sv_netview_offsetfromdp(11740200);
        xsim_sc_channel<0, bool > *p_1_DDR_Clk = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_Clk.bind(*p_1_DDR_Clk);
        p_1_DDR_Clk->set_sv_netview_offsetfromdp(11740256);
        xsim_sc_channel<0, bool > *p_1_DDR_CS_n = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_CS_n.bind(*p_1_DDR_CS_n);
        p_1_DDR_CS_n->set_sv_netview_offsetfromdp(11740312);
        xsim_sc_channel<0, bool > *p_1_DDR_DRSTB = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_DRSTB.bind(*p_1_DDR_DRSTB);
        p_1_DDR_DRSTB->set_sv_netview_offsetfromdp(11740368);
        xsim_sc_channel<0, bool > *p_1_DDR_ODT = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_ODT.bind(*p_1_DDR_ODT);
        p_1_DDR_ODT->set_sv_netview_offsetfromdp(11740424);
        xsim_sc_channel<0, bool > *p_1_DDR_RAS_n = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_RAS_n.bind(*p_1_DDR_RAS_n);
        p_1_DDR_RAS_n->set_sv_netview_offsetfromdp(11740480);
        xsim_sc_channel<0, bool > *p_1_DDR_WEB = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_WEB.bind(*p_1_DDR_WEB);
        p_1_DDR_WEB->set_sv_netview_offsetfromdp(11740536);
        xsim_sc_channel<3, sc_dt::sc_bv<3> > *p_1_DDR_BankAddr = new xsim_sc_channel<3, sc_dt::sc_bv<3> >();
        sc_inst_1->DDR_BankAddr.bind(*p_1_DDR_BankAddr);
        p_1_DDR_BankAddr->set_sv_netview_offsetfromdp(11740592);
        xsim_sc_channel<15, sc_dt::sc_bv<15> > *p_1_DDR_Addr = new xsim_sc_channel<15, sc_dt::sc_bv<15> >();
        sc_inst_1->DDR_Addr.bind(*p_1_DDR_Addr);
        p_1_DDR_Addr->set_sv_netview_offsetfromdp(11740648);
        xsim_sc_channel<0, bool > *p_1_DDR_VRN = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_VRN.bind(*p_1_DDR_VRN);
        p_1_DDR_VRN->set_sv_netview_offsetfromdp(11740704);
        xsim_sc_channel<0, bool > *p_1_DDR_VRP = new xsim_sc_channel<0, bool >();
        sc_inst_1->DDR_VRP.bind(*p_1_DDR_VRP);
        p_1_DDR_VRP->set_sv_netview_offsetfromdp(11740760);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_DDR_DM = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->DDR_DM.bind(*p_1_DDR_DM);
        p_1_DDR_DM->set_sv_netview_offsetfromdp(11740816);
        xsim_sc_channel<32, sc_dt::sc_bv<32> > *p_1_DDR_DQ = new xsim_sc_channel<32, sc_dt::sc_bv<32> >();
        sc_inst_1->DDR_DQ.bind(*p_1_DDR_DQ);
        p_1_DDR_DQ->set_sv_netview_offsetfromdp(11740872);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_DDR_DQS_n = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->DDR_DQS_n.bind(*p_1_DDR_DQS_n);
        p_1_DDR_DQS_n->set_sv_netview_offsetfromdp(11740928);
        xsim_sc_channel<4, sc_dt::sc_bv<4> > *p_1_DDR_DQS = new xsim_sc_channel<4, sc_dt::sc_bv<4> >();
        sc_inst_1->DDR_DQS.bind(*p_1_DDR_DQS);
        p_1_DDR_DQS->set_sv_netview_offsetfromdp(11740984);
        xsim_sc_channel<0, bool > *p_1_PS_SRSTB = new xsim_sc_channel<0, bool >();
        sc_inst_1->PS_SRSTB.bind(*p_1_PS_SRSTB);
        p_1_PS_SRSTB->set_sv_netview_offsetfromdp(11741040);
        xsim_sc_channel<0, bool > *p_1_PS_CLK = new xsim_sc_channel<0, bool >();
        sc_inst_1->PS_CLK.bind(*p_1_PS_CLK);
        p_1_PS_CLK->set_sv_netview_offsetfromdp(11741096);
        xsim_sc_channel<0, bool > *p_1_PS_PORB = new xsim_sc_channel<0, bool >();
        sc_inst_1->PS_PORB.bind(*p_1_PS_PORB);
        p_1_PS_PORB->set_sv_netview_offsetfromdp(11741152);
    }


extern "C"
    void implicit_HDL_SCcleanup()
    {
        delete sc_inst_1;
    }
