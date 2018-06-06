###########################
#### Implement Modules ####
###########################
proc impl {impl} {
   global part
   global dcpLevel
   global verbose
   global implDir
   global xdcDir
   global dcpDir
   global modules
   global ooc_implementations 

   set top                 [get_impl_attribute $impl top]
   set implXDC             [get_impl_attribute $impl implXDC]
   set linkXDC             [get_impl_attribute $impl linkXDC]
   set cores               [get_impl_attribute $impl cores]
   set hd                  [get_impl_attribute $impl hd.impl]
   set td                  [get_impl_attribute $impl td.impl]
   set link                [get_impl_attribute $impl link]
   set opt                 [get_impl_attribute $impl opt]
   set opt.pre             [get_impl_attribute $impl opt.pre]
   set opt_options         [get_impl_attribute $impl opt_options]
   set opt_directive       [get_impl_attribute $impl opt_directive]
   set place               [get_impl_attribute $impl place]
   set place.pre           [get_impl_attribute $impl place.pre]
   set place_options       [get_impl_attribute $impl place_options]
   set place_directive     [get_impl_attribute $impl place_directive]
   set phys                [get_impl_attribute $impl phys]
   set phys.pre            [get_impl_attribute $impl phys.pre]
   set phys_options        [get_impl_attribute $impl phys_options]
   set phys_directive      [get_impl_attribute $impl phys_directive]
   set route               [get_impl_attribute $impl route]
   set route.pre           [get_impl_attribute $impl route.pre]
   set route_options       [get_impl_attribute $impl route_options]
   set route_directive     [get_impl_attribute $impl route_directive]
   set bitstream           [get_impl_attribute $impl bitstream]
   set bitstream.pre       [get_impl_attribute $impl bitstream.pre]
   set bitstream_options   [get_impl_attribute $impl bitstream_options]


   if {$hd && $td} {
      set errMsg "ERROR: Implementation $impl has both hd.impl and td.impl set to '1'. This is not valid. To run both of these flows, create separate implementation runs."
      error $errMsg
   }
   # Make the implementation directory if needed
   if {![file exists $implDir]} {
      command "file mkdir $implDir"
   }
   set resultDir "$implDir/$impl"
   set reportDir "$resultDir/reports"
   puts "\tWriting results to: $resultDir"
   puts "\tWriting reports to: $reportDir"

   ###########################################
   # Linking
   ###########################################
   if {$link} {
      command "file delete -force $resultDir"
      command "file mkdir $resultDir"
      command "file mkdir $reportDir"
   
      #Create in-memory project
      command "create_project -in_memory -part $part" "$resultDir/create_project.log"
   
      ###########################################
      # Define the top-level sources
      ###########################################
      foreach module $modules {
         set name [get_module_attribute $module moduleName]
         if {[string match $name $top]} {
            set topFile [get_module_file $module]
         }
      }
      if {[info exists topFile]} {
         command "add_files $topFile"
      } else {
         set errMsg "ERROR: No module found with with attribute \"moduleName\" equal to $top, which is defined as \"top\" for implementation $impl."
         error $errMsg
      }
   
      #### Read in IP Netlists 
      if {[llength $cores] > 0} {
         add_cores $cores
      }
      
      #### Read in XDC file
      if {[llength $implXDC] > 0} {
         add_xdc $implXDC
      } else {
         puts "\tWARNING: No XDC file specified for $impl"
      }
   
      ##############################################
      # Link the top-level design with black boxes 
      ##############################################
      set time [clock seconds]
      puts "\t#HD: Running link_design for $top \[[clock format $time -format {%a %b %d %H:%M:%S %Y}]\]"
      command "link_design -mode default -part $part -top $top" "$resultDir/${top}_link_design.log"
   
      ##############################################
      # Bring in OOC module check points
      ##############################################
      if {$hd && [llength $ooc_implementations] > 0} {
         get_ooc_results $ooc_implementations
      }

      ##############################################
      # Read in any linkXDC files 
      ##############################################
      if {[llength $linkXDC] > 0} {
         readXDC $linkXDC
      }

      puts "\t#HD: Completed link_design"
      puts "\t##########################\n"
      if {$dcpLevel > 0} {
         command "write_checkpoint -force $resultDir/${top}_link_design.dcp" "$resultDir/temp.log"
      }
      if {$verbose > 1} {
         command "report_utilization -file $reportDir/${top}_utilization_link_design.rpt" "$resultDir/temp.log"
      } 

      if {$td} {
         puts "\t#HD: Creating OOC constraints"
         foreach ooc $ooc_implementations {
            #Set HD.PARTITION and create set_logic_* constraints
            set instName [get_ooc_attribute $ooc inst]
            set hierInst [get_ooc_attribute $ooc hierInst]
            command "set_property HD.PARTITION 1 \[get_cells $hierInst\]"
            set_partpin_range $hierInst
            create_set_logic $instName $hierInst $xdcDir
            create_ooc_clocks $instName $hierInst $xdcDir
         }
         command "write_checkpoint -force $resultDir/${top}_link_design.dcp" "$resultDir/temp.log"
      }
      #Run methodology DRCs and cattch any Critical Warnings or Error (module ruledeck quiet)
      check_drc $top methodology_checks 1
      #Run timing DRCs and cattch any Critical Warnings or Error (module ruledeck quiet)
      check_drc $top timing_checks 1
   }
   
   ############################################################################################
   # Implementation steps: opt_design, place_design, phys_opt_design, route_design
   ############################################################################################
   set impl_start [clock seconds]
   if {$opt} {
      impl_step opt_design $top $opt_options $opt_directive ${opt.pre}
   }
   if {$place} {
      impl_step place_design $top $place_options $place_directive ${place.pre}

      #### If Top-Down, write out XDCs 
      if {$td} {
         puts "\n\tWriting instance level XDC files."
         foreach ooc $ooc_implementations {
            set instName [get_ooc_attribute $ooc inst]
            set hierInst [get_ooc_attribute $ooc hierInst]
            write_hd_xdc $instName $hierInst $xdcDir
         }
      }
   }
   if {$phys} {
      impl_step phys_opt_design $top $phys_options $phys_directive ${phys.pre}
   }
   if {$route} {
      impl_step route_design $top $route_options $route_directive ${route.pre}
 
      #Run report_timing_summary on final design
      command "report_timing_summary -file $reportDir/${top}_timing_summary.rpt" "$resultDir/temp.log"
   
      #Run a final DRC that catches any Critical Warnings (module ruledeck quiet)
      check_drc $top bitstream_checks 0
   
   }
   
   set impl_end [clock seconds]
   log_time final $impl_start $impl_end 
   log_data $impl $top

   if {$bitstream} {
      impl_step write_bitstream $top $bitstream_options none ${bistream.pre}
   }
   
   command "close_project"
   command "\n"
}
