`timescale 1ns / 1ps
`default_nettype none
/* This module describes the gate-level model of *
 * a fulle-adder in Verilog                      */
 
 module full_adder(S, Cout, A, B, Cin);
 
    /*declare output and input ports*/
    output wire S, Cout;   //1-bit output wires
    input wire A, B, Cin; //1-bit input wires
    
    /*declare internal nets*/
    wire andBCin, andACin, andAB; //1-bit wires
    
    /*use dataflow to describe the gate-level activity*/
    assign #6 S = A ^ B ^ Cin; //the hat (^) is for XOR
    assign #4 andAB = A & B;   //the ampersand (&) is for and
    assign #4 andBCin = B & Cin;
    assign #4 andACin = A & Cin;
    assign #6 Cout = andAB | andBCin | andACin; //pipe (|) is for or

endmodule