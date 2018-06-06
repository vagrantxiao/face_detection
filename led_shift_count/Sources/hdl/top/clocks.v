//----------------------------------------------------------------------------
// Output     Output      Phase    Duty Cycle   Pk-to-Pk     Phase
// Clock     Freq (MHz)  (degrees)    (%)     Jitter (ps)  Error (ps)
//----------------------------------------------------------------------------
// clk_out   100.000      0.000    50.000      122.885     92.672

//
//----------------------------------------------------------------------------
// Input Clock   Input Freq (MHz)   Input Jitter (UI)
//----------------------------------------------------------------------------
// primary         200.000            0.010

`timescale 1ps/1ps

module clocks
 (// Clock in ports
  input         clk_n,
  // Clock out ports
  output        clk_out
 );

  wire clkin1;
  BUFG clkin1_buf (
    .O(clk_out), // 1-bit output: Clock output
    .I(clk_n)  // 1-bit input: Clock input
   );
   

endmodule
