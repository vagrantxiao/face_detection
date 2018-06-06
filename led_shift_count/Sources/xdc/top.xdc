
####################################################################################
# Constraints from file : 'top.xdc'
####################################################################################

#///////////////////////////////////////////////////////////////////////////////
#// Copyright (c) 2005-2009 Xilinx, Inc.
#// This design is confidential and proprietary of Xilinx, Inc.
#// All Rights Reserved.
#///////////////////////////////////////////////////////////////////////////////
#//   ____  ____
#//  /   /\/   /
#// /___/  \  /   Vendor: Xilinx
#// \   \   \/    Version: 2013.3
#//  \   \        Application: Partial Reconfiguration
#//  /   /        Filename: top.ucf
#// /___/   /\    Date Last Modified: 8 October 2013
#// \   \  /  \
#//  \___\/\___\
#// Device: KC705 board Rev B
#// Design Name: led_shift_count_gsr
#// Purpose: Partial Reconfiguration User Guide
#///////////////////////////////////////////////////////////////////////////////

###############################################################################
# User Time Names / User Time Groups / Time Specs
###############################################################################
create_clock -name clk_n -period 5 [get_ports clk_n]

#-------------------------------------------------
# pblock_count 
#            for pr instance reconfig_module_count
#-------------------------------------------------
create_pblock pblock_count
add_cells_to_pblock [get_pblocks pblock_count]  [get_cells -quiet [list inst_count]]
resize_pblock [get_pblocks pblock_count] -add {SLICE_X0Y0:SLICE_X11Y49}
resize_pblock [get_pblocks pblock_count] -add {RAMB18_X0Y0:RAMB18_X0Y19}
resize_pblock [get_pblocks pblock_count] -add {RAMB36_X0Y0:RAMB36_X0Y9}
set_property RESET_AFTER_RECONFIG 1 [get_pblocks pblock_count]

#-------------------------------------------------
# pblock_shift 
#            for pr instance reconfig_module_shift
#-------------------------------------------------
create_pblock pblock_shift
add_cells_to_pblock [get_pblocks pblock_shift]  [get_cells -quiet [list inst_shift]]
resize_pblock pblock_shift -add {SLICE_X102Y100:SLICE_X113Y149 RAMB18_X5Y40:RAMB18_X5Y59 RAMB36_X5Y20:RAMB36_X5Y29}
set_property RESET_AFTER_RECONFIG 1 [get_pblocks pblock_shift]

#-----------------------------------
# LED LOCs 
#    LED[0-3] shift
#    LED[4-7] count
#-----------------------------------
#Net shift_out[0] LOC=AB8; # GPIO_LED0_LS on Bank33 (VCC1V5 1.5 volt)
set_property PACKAGE_PIN U14 [get_ports shift_out[0]]
set_property IOSTANDARD LVCMOS25 [get_ports shift_out[0]]

# GPIO_LED1_LS on Bank33 (VCC1V5 1.5 volt)
set_property PACKAGE_PIN U19 [get_ports shift_out[1]]
set_property IOSTANDARD LVCMOS25 [get_ports shift_out[1]]

# GPIO_LED2_LS on Bank33 (VCC1V5 1.5 volt)
set_property PACKAGE_PIN W22 [get_ports shift_out[2]]
set_property IOSTANDARD LVCMOS25 [get_ports shift_out[2]]

# GPIO_LED3_LS on Bank33 (VCC1V5 1.5 volt)
set_property PACKAGE_PIN V22 [get_ports shift_out[3]]
set_property IOSTANDARD LVCMOS25 [get_ports shift_out[3]]

# GPIO_LED4_LS on Bank13 (VADJ 2.5 volt)
set_property PACKAGE_PIN U21 [get_ports count_out[3]]
set_property IOSTANDARD LVCMOS25 [get_ports count_out[3]]

# GPIO_LED5_LS on Bank17 (VADJ 2.5 volt)
set_property PACKAGE_PIN U22 [get_ports count_out[2]]
set_property IOSTANDARD LVCMOS25 [get_ports count_out[2]]

# GPIO_LED6_LS on Bank17 (VADJ 2.5 volt)
set_property PACKAGE_PIN T21 [get_ports count_out[1]]
set_property IOSTANDARD LVCMOS25 [get_ports count_out[1]]

# GPIO_LED7_LS on Bank18 (VADJ 2.5 volt)
set_property PACKAGE_PIN T22 [get_ports count_out[0]]
set_property IOSTANDARD LVCMOS25 [get_ports count_out[0]]



# For Programable Clock Source over SMA
#set_property PACKAGE_PIN Y9 [get_ports clk_p]
#set_property IOSTANDARD LVDS_25 [get_ports clk_p]

#set_property PACKAGE_PIN Y8 [get_ports clk_n]
#set_property IOSTANDARD LVDS_25 [get_ports clk_n]

set_property PACKAGE_PIN Y9 [get_ports clk_n]
set_property IOSTANDARD LVCMOS25 [get_ports clk_n]

#-----------------------------------
# push buttons LOCs
#-----------------------------------
# Reset Button on Switch SW5 "Center Button"
# GPIO_SW_C on Bank18 (VADJ 2.5 volt)
set_property PACKAGE_PIN F22 [get_ports rst_n]
set_property IOSTANDARD LVCMOS25 [get_ports rst_n]


#-----------------------------------
# End
#-----------------------------------
