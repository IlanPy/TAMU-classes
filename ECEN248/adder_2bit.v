`timescale 1ns / 1ps
`default_nettype none

module adder_2bit(Carry, Sum, A, B);
    output wire Carry; //carry is a 1-bit output
    output wire [1:0] Sum; //Sum is a 2-bit output
    input wire [1:0] A, B; //A, B are 2-bit inputs
    
    /*declare internal wire*/
    wire Cout;
    
    /*utilize full adders to build ripple carry*/
    full_adder full_adder0(Sum[0], Cout, A[0], B[0], 1'b0);
    full_adder full_adder1(Sum[1], Carry, A[1], B[1], Cout);
    
endmodule