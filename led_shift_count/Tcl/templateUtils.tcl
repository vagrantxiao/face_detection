###############################################################
# Generates verilog or vhdl templates for current_instance or
# specfied cell. 
# - Requires design loaded in memory
# - Generates stub, instantitation template, or testbench
###############################################################
proc writeTemplate { args } {

   #set Default values
   set outFile "temp_stub.v"
   set type "stub"
   set language "verilog"
   array set options {-type $type -language $language -cell none -file $outFile }

   #Override defaults with command options
   set argLength [llength $args]
   set index 0
   while {$index < $argLength} {
      set arg [lindex $args $index]
      set value [lindex $args [expr $index+1]]
      switch -exact -- $arg {
         {-type}     {if {[string match "stub" $value] \
                       || [string match "template" $value] \
                       || [string match "testbench" $value]} {
                         set options($arg) [lindex $args [incr index]]
                         set type $value
                      } else {
                         set errMsg "ERROR: Specified arguement $arg with value $value does not match the expected value.\n"
                         append errMsg "The supported values for $arg are stub, template, or testbench."
                         error $errMsg
                      }
                     }
         {-language} {if {[string match "vhdl" $value] \
                       || [string match "verilog" $value]} {
                         set options($arg) [lindex $args [incr index]]
                         set language $value
                      } else {
                         set errMsg "ERROR: Specified arguement $arg with value $value does not match the expected value.\n"
                         append errMsg "The supported values for $arg are vhdl or verilog."
                         error $errMsg
                      }
                     }
         {-cell}     {if {[llength [get_cells $value]]} {
                         set options($arg) [lindex $args [incr index]]
                         set cell $value
                      } else {
                         set errMsg "ERROR: Specified cell $value could not be found in design."
                         error $errMsg
                      }
                     }
         {-file}     {set options($arg) [lindex $args [incr index]]
                      set outFile $value
                     }
         {-help}     {set     helpMsg "Description:"
                      lappend helpMsg "Writes out verilog or vhdl templates for:"
                      lappend helpMsg "\t-module template"
                      lappend helpMsg "\t-module blackbox stub definition"
                      lappend helpMsg "\t-module testbench.\n"
                      lappend helpMsg "Syntax:"
                      lappend helpMsg "writeTemplate\t\[-type <arg>] \[-language <arg>] \[-cell <arg>] \[-file <arg>]\n"
                      lappend helpMsg "Usage:"
                      lappend helpMsg "  Name                        Description"
                      lappend helpMsg "  ---------------------------------------"
                      lappend helpMsg "  \[-type]                     Specifies the type of template to create. Options are"
                      lappend helpMsg "                              stub,template, or testbench. Default value is stub"
                      lappend helpMsg "  \[-language]                 Specifies the output language of the template. Options"
                      lappend helpMsg "                              are verilog or vhdl. Default value is verilog."
                      lappend helpMsg "  \[-cell]                     Cell to generate template on. If not specified, runs on"
                      lappend helpMsg "                              current_instance"
                      lappend helpMsg "  \[-file]                     Specifies the output file name. If not specified the"
                      lappend helpMsg "                              output will be written to temp_stub.v"
                      lappend helpMsg "  \[-help]                     Displays this message\n\n"
                      foreach line $helpMsg {
                         puts $line
                      }
                      return
                     }
         default     {set errMsg "ERROR: Specified argument $arg is not supported.\n"
                      append errMsg "Supported arguments are -help, -type, -language, -cell, and -file.\n"
                      append errMsg "Use the -help option for more details"
                      error $errMsg 
                     }
      }
      incr index
   }

   #If no design is open
   if { [catch {current_instance}]} {
      set errMsg "ERROR: No open design. A design must be open to run this command."
      error $errMsg
   }

   #Define module name and if command is being run on top or a cell 
   if {[info exists cell]} {
      set module [get_property LIB_CELL [get_cells $cell]]
      set isTop 0
   } else {
      set module [current_instance]
      set isTop 1
   }

   #Open the output file for writting
   puts "Creating $language $type for Module $module in $outFile."
   set tfh [open $outFile w]

   #Get a sorted list of all input and output bit and busses 
   #If no -cell, this is a list of ports as input and output
   #If a cell is specified, a list of pins is given, but a scoped port list is returned
   if {$isTop} {
      set inPorts [lsort [get_ports -filter DIRECTION==IN]]
      array set inputBusPorts [list ]
      set inputBitPorts ""
      sortPorts $inPorts inputBusPorts inputBitPorts

      set outPorts [lsort [get_ports -filter DIRECTION==OUT]]
      array set outputBusPorts [list ]
      set outputBitPorts ""
      sortPorts $outPorts outputBusPorts outputBitPorts
   } else {
      set inPins [lsort [get_pins -of [get_cells $cell] -filter DIRECTION==IN]]
      array set inputBusPorts [list ]
      set inputBitPorts ""
      sortPins $inPins inputBusPorts inputBitPorts
      
      set outPins [lsort [get_pins -of [get_cells $cell] -filter DIRECTION==OUT]]
      array set outputBusPorts [list ]
      set outputBitPorts ""
      sortPins $outPins outputBusPorts outputBitPorts
   }


   if {[string match $type "stub"]} {
      if {[string match $language "verilog"]} {
         vlogStub
      } elseif {[string match $language "vhdl"]} {
         vhdlStub
      }
   } elseif {[string match $type "template"]} {
      if {[string match $language "verilog"]} {
         vlogTemplate
      } elseif {[string match $language "vhdl"]} {
         vhdlTemplate
      }
   } elseif {[string match $type "testbench"]} {
      if {[string match $language "verilog"]} {
         vlogTestBench
      } elseif {[string match $language "vhdl"]} {
         vhdlTestBench
      }
   }
}

###############################################################
# Generates a Verilog instantiation template for the specified
# module.
###############################################################
proc vlogTemplate {} {
   upvar tfh tfh
   upvar module module
   upvar inputBitPorts inputBitPorts
   upvar inputBusPorts inputBusPorts
   upvar outputBitPorts outputBitPorts
   upvar outputBusPorts outputBusPorts

   puts $tfh "$module ${module}_inst ("

   set lines ""
   #Process input single bit ports
   lappend lines "\/\/Input Ports - Single Bit"
   foreach port $inputBitPorts {
      lappend lines ".${port} ($port),"
   }
   #Process input bus ports
   lappend lines "\/\/Input Ports - Busses"
   foreach {port busInfo} [array get inputBusPorts] {
      lassign $busInfo width stop start
      lappend lines ".${port}\[$start:$stop\] ($port\[$start:$stop\]),"
   }
   #Process output single bit ports
   lappend lines "\/\/Output Ports - Single Bit"
   set count 1
   foreach port $outputBitPorts {
      if {[llength $outputBitPorts]==$count && [array size outputBusPorts]==0} {
         lappend lines "output $port"
      } else {
         lappend lines ".${port} ($port),"
         incr count
      }
   }
   #Process output bus ports
   lappend lines "\/\/Output Ports - Busses"
   set count 1
   foreach {port busInfo} [array get outputBusPorts] {
      lassign $busInfo width stop start
      if {[array size outputBusPorts] == $count} {
         lappend lines ".${port}\[$start:$stop\] ($port\[$start:$stop\])"
      } else {
         lappend lines ".${port}\[$start:$stop\] ($port\[$start:$stop\]),"
         incr count
      }
   }

   #Detect maximum column width to align columns
   foreach line $lines {
      set width [string length [lindex $line 0]]
      if {![info exist maxWidth] || $maxWidth < $width} {
         set maxWidth $width
      }
   }
   
   #Construct Formatted lines to align columns and print each line to output file
   foreach line $lines {
      set print ""
      set splitline [split $line (]
      set count 0
      foreach index $splitline {
         if {$count==0} {
             if {[string match "\/\/*" $index]} {
                append print "   $index "
             } else {
                append print "   "
                append print [format "%-*s " $maxWidth $index]
                append print "("
             }
         } else {
             append print $index
         }
         incr count
      }
      puts $tfh "$print"
   }
   puts $tfh ");"
   close $tfh
}

###############################################################
# Generates a VHDL instantiation template for the specified
# module.
###############################################################
proc vhdlTemplate {} {
   upvar tfh tfh
   upvar module module
   upvar inputBitPorts inputBitPorts
   upvar inputBusPorts inputBusPorts
   upvar outputBitPorts outputBitPorts
   upvar outputBusPorts outputBusPorts

   puts $tfh "${module}_inst: ${module}"
   puts $tfh "   port map (" 

   set lines ""
   #Process input single bit ports
   lappend lines "--Input Ports - Bitwide"
   foreach port $inputBitPorts {
      lappend lines "$port => $port,"
   }
   #Process input bus ports
   lappend lines "--Input Ports - Busses"
   foreach {port busInfo} [array get inputBusPorts] {
      lassign $busInfo width stop start
      lappend lines "${port}($start downto $stop) => ${port}($start downto $stop),"
   }
   #Process output single bit ports
   lappend lines "--Output Ports - Bitwide"
   set count 1
   foreach port $outputBitPorts {
      if {[llength $outputBitPorts]==$count && [array size outputBusPorts] == 0} {
         lappend lines "$port => $port,"
      } else {
         lappend lines "$port => $port"
         incr count
      }
   }
   #Process output bus ports
   lappend lines "--Output Ports - Busses"
   set count 1
   foreach {port busInfo} [array get outputBusPorts] {
      lassign $busInfo width stop start
      if {[array size outputBusPorts] == $count} {
         lappend lines "${port}($start downto $stop) => ${port}($start downto $stop)"
      } else {
         lappend lines "${port}($start downto $stop) => ${port}($start downto $stop),"
         incr count
      }
   }

   #Detect maximum column width to align columns
   foreach line $lines {
      #Ignore commented lines
      if {![regexp "\-\-.*" $line]} {
         set splitline [split $line =>]
         set width [string length [lindex $splitline 0]]
         if {![info exist maxWidth] || $maxWidth < $width} {
            set maxWidth $width
         }
      }
   }
   
   #Construct Formatted lines to align columns and print each line to output file
   foreach line $lines {
      set print ""
      set splitline [split $line =>]
      set count 0
      foreach index $splitline {
         if {$count==0} {
             append print "      "
             append print [format "%-*s " $maxWidth $index]
             if {![string match "--*" $index]} {
                append print "=> "
             }
         } else {
             append print $index
         }
         incr count
      }
      puts $tfh "$print"
   }
   puts $tfh "   );"
   close $tfh
}

###############################################################
# Generates a Verilog blackbox entity declaration for the specified
# module. 
###############################################################
proc vlogStub {} {
   upvar tfh tfh
   upvar module module
   upvar inputBitPorts inputBitPorts
   upvar inputBusPorts inputBusPorts
   upvar outputBitPorts outputBitPorts
   upvar outputBusPorts outputBusPorts

   puts $tfh "module ${module}("

   set lines ""
   #Process input single bit ports
   lappend lines "\/\/Input Ports - Single Bit"
   foreach port $inputBitPorts {
      lappend lines "input  $port,"
   }
   #Process input bus ports
   lappend lines "\/\/Input Ports - Busses"
   foreach {port busInfo} [array get inputBusPorts] {
      lassign $busInfo width stop start
      lappend lines "input  $port\[$start:$stop\],"
   }
   #Process output single bit ports
   lappend lines "\/\/Output Ports - Single Bit"
   set count 1
   foreach port $outputBitPorts {
      if {[llength $outputBitPorts]==$count && [array size outputBusPorts]==0} {
         lappend lines "output $port"
      } else {
         lappend lines "output $port,"
         incr count
      }
   }
   #Process output bus ports
   lappend lines "\/\/Output Ports - Busses"
   set count 1
   foreach {port busInfo} [array get outputBusPorts] {
      lassign $busInfo width stop start
      if {[array size outputBusPorts] == $count} {
         lappend lines "output $port\[$start:$stop\]"
      } else {
         lappend lines "output $port\[$start:$stop\],"
         incr count
      }
   }

   foreach line $lines {
      puts $tfh "   $line"
   }
   puts $tfh ");"
   close $tfh
}

###############################################################
# Generates a VHDL blackbox entity declaration for the specified
# module. 
###############################################################
proc vhdlStub {} {
   upvar tfh tfh
   upvar module module
   upvar inputBitPorts inputBitPorts
   upvar inputBusPorts inputBusPorts
   upvar outputBitPorts outputBitPorts
   upvar outputBusPorts outputBusPorts

   puts $tfh "library IEEE;"
   puts $tfh "use IEEE.std_logic_1164.all;"
   puts $tfh "entity ${module} is"
   puts $tfh "   port ("

   set lines ""
   #Process input single bit ports
   lappend lines "--Input Ports - Single Bit"
   foreach port $inputBitPorts {
      lappend lines "$port: in  std_logic;"
   }
   #Process input bus ports
   lappend lines "--Input Ports - Busses"
   foreach {port busInfo} [array get inputBusPorts] {
      lassign $busInfo width stop start
      lappend lines "$port: in  std_logic_vector($start downto $stop);"
   }
   #Process output single bit ports
   lappend lines "--Output Ports - Single Bit"
   set count 1
   foreach port $outputBitPorts {
      if {[llength $outputBitPorts]==$count && [array size outputBusPorts] == 0} {
         lappend lines "$port: out std_logic"
      } else {
         lappend lines "$port: out std_logic;"
         incr count
      }
   }
   #Process output bus ports
   lappend lines "--Output Ports - Busses"
   set count 1
   foreach {port busInfo} [array get outputBusPorts] {
      lassign $busInfo width stop start
      if {[array size outputBusPorts] == $count} {
         lappend lines "$port: out std_logic_vector($start downto $stop)"
      } else {
         lappend lines "$port: out std_logic_vector($start downto $stop);"
         incr count
      }
   }

   #Detect maximum column width to align columns
   foreach line $lines {
      #Ignore commented lines
      if {![regexp "\-\-.*" $line]} {
         set splitline [split $line :]
         set width [string length [lindex $splitline 0]]
         if {![info exist maxWidth] || $maxWidth < $width} {
            set maxWidth $width
         }
      }
   }
   
   #Construct Formatted lines to align columns and print each line to output file
   foreach line $lines {
      set print ""
      set splitline [split $line :]
      set count 0
      foreach index $splitline {
         if {$count==0} {
             append print "      "
             append print [format "%-*s " $maxWidth $index]
             if {![string match "--*" $index]} {
                append print ": "
             }
         } else {
             append print $index
         }
         incr count
      }
      puts $tfh "$print"
   }
   puts $tfh "   );"
   puts $tfh "end entity ${module};"
   close $tfh
}

###############################################################
# Generates a Verilog testbench for specified module
###############################################################
proc vlogTestBench {} {
   puts "This feature is not yet implemented"
}

###############################################################
# Generates a VHDL testbench for specified module
###############################################################
proc vhdlTestBench {} {
   puts "This feature is not yet implemented"
}

###############################################################
# Sort list of pins into busses and bit ports by removing
# hiearchical prefixes, and assigns them to the specified
# array and list, respectively.
###############################################################
proc sortPins { pins &bus bit } {
   upvar ${&bus} busPorts
   upvar $bit bitPorts
   array set busPorts [list ]
   set bitPorts ""

   foreach pin $pins {
      set busName [get_property BUS_NAME [get_pins $pin]]
      if {![info exist BusPorts($busName)] && [llength $busName]} {
         set busWidth [get_property BUS_WIDTH [get_pins $pin]]
         set busStart [get_property BUS_START [get_pins $pin]]
         set busStop  [get_property BUS_STOP  [get_pins $pin]]
         array set busPorts [list $busName [list $busWidth $busStop $busStart]]
      } elseif {[llength $busName] == 0} {
         set pin_split [split $pin "/"]
         set port [lindex $pin_split end]
         lappend bitPorts $port         
      }
   } 
}

###############################################################
# Sort list of ports into busses and bit ports, and assigns
# them to the specified array and list, respectively.
###############################################################
proc sortPorts { ports &bus bit} {
   upvar ${&bus} busPorts
   upvar $bit bitPorts
   array set busPorts [list ]
   set bitPorts ""

   foreach port $ports {
      set busName [get_property BUS_NAME [get_ports $port]]
      if {![info exist BusPorts($busName)] && [llength $busName]} {
         set busWidth [get_property BUS_WIDTH [get_ports $port]]
         set busStart [get_property BUS_START [get_ports $port]]
         set busStop  [get_property BUS_STOP  [get_ports $port]]
         array set busPorts [list $busName [list $busWidth $busStop $busStart]]
      } elseif {[llength $busName] == 0} {
         lappend bitPorts $port         
      }
   } 
}

