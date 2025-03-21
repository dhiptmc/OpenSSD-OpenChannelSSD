
set_property OUTPUT_IMPEDANCE RDRV_40_40 [get_ports nand_if_0_nand_dqs_p]
set_property OUTPUT_IMPEDANCE RDRV_48_48 [get_ports nand_if_1_nand_dqs_p]
set_property OUTPUT_IMPEDANCE RDRV_48_48 [get_ports nand_if_2_nand_dqs_p]
set_property OUTPUT_IMPEDANCE RDRV_48_48 [get_ports nand_if_3_nand_dqs_p]
set_property ODT RTT_40 [get_ports nand_if_0_nand_dqs_p]
#set_property ODT RTT_48 [get_ports nand_if_1_nand_dqs_p]
#set_property ODT RTT_48 [get_ports nand_if_2_nand_dqs_p]
set_property ODT RTT_48 [get_ports nand_if_3_nand_dqs_p]
set_property OUTPUT_IMPEDANCE RDRV_40_40 [get_ports nand_if_0_nand_re_p]
set_property OUTPUT_IMPEDANCE RDRV_48_48 [get_ports nand_if_1_nand_re_p]
set_property OUTPUT_IMPEDANCE RDRV_48_48 [get_ports nand_if_2_nand_re_p]
set_property OUTPUT_IMPEDANCE RDRV_48_48 [get_ports nand_if_3_nand_re_p]
#set_property ODT RTT_48 [get_ports nand_if_*_nand_dqs_p]

set_property PULLDOWN true [get_ports nand_if_0_nand_dqs_p]
set_property PULLDOWN true [get_ports nand_if_1_nand_dqs_p]
set_property PULLDOWN true [get_ports nand_if_2_nand_dqs_p]
set_property PULLDOWN true [get_ports nand_if_3_nand_dqs_p]
set_property PULLUP true [get_ports nand_if_0_nand_dqs_n]
set_property PULLUP true [get_ports nand_if_1_nand_dqs_n]
set_property PULLUP true [get_ports nand_if_2_nand_dqs_n]
set_property PULLUP true [get_ports nand_if_3_nand_dqs_n]

set_property SLEW FAST [get_ports nand_if_*_nand_dqs_p]
set_property SLEW FAST [get_ports nand_if_*_nand_re_p]















set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_ale]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_cle]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_dqs_p]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_re_p]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_we]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_wp]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_ale]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_cle]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_dqs_p]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_re_p]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_we]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_wp]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_ale]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_cle]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_dqs_p]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_re_p]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_we]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_wp]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_ale]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_cle]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_dqs_p]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_re_p]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_we]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_wp]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_ce[7]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_ce[6]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_ce[5]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_ce[4]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_ce[3]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_ce[2]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_ce[1]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_ce[0]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_dq[7]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_dq[6]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_dq[5]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_dq[4]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_dq[3]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_dq[2]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_dq[1]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_0_nand_dq[0]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_ce[7]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_ce[6]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_ce[5]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_ce[4]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_ce[3]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_ce[2]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_ce[1]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_ce[0]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_dq[7]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_dq[6]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_dq[5]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_dq[4]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_dq[3]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_dq[2]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_dq[1]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_1_nand_dq[0]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_ce[7]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_ce[6]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_ce[5]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_ce[4]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_ce[3]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_ce[2]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_ce[1]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_ce[0]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_dq[7]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_dq[6]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_dq[5]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_dq[4]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_dq[3]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_dq[2]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_dq[1]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_2_nand_dq[0]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_ce[7]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_ce[6]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_ce[5]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_ce[4]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_ce[3]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_ce[2]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_ce[1]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_ce[0]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_dq[7]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_dq[6]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_dq[5]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_dq[4]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_dq[3]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_dq[2]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_dq[1]]
set_property OFFCHIP_TERM NONE [get_ports nand_if_3_nand_dq[0]]

