`timescale 1ns / 1ps
`default_nettype none
/*This Verilog module describes a 2-bit ripple carry adder */
 
 module adder_2bit(
    /*declare output and input ports */
    output wire [1:0] S,  //2-bit output for sum
    output wire Cout,      //1-bit output for carry
    input wire [1:0] A, B,  //2-bit input wires
    input wire Cin            //1-bit wire for Cin
);
    /*declar internal wire for first Cout*/
    wire Cout0;
    
    /*complement logic*/
    assign S[0] = (A[0] ^ B[0]) ^ Cin
    assign Cout0 = ((A[0] ^ B[0]) & Cin) | (A[0] & B[0])
    
    assign S[1] = (A[1] ^ B[1]) ^ Cout
    assign Cout = ((A[1] ^ B[1]) & Cout) | (A[1] & B[1])
    
endmodule