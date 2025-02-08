`timescale 1ns / 1ps //delay unit is 1ns
`default_nettype none

module d_flip_flop_behavioral(
    output reg Q,
    output wire notQ,
    input wire D,
    input wire Clk //clock signal
    );
    
    /*describe behavior of D flip-flop*/
    //posedge means positive (rising edge)
    always@(posedge Clk) //trigger when Clk goes HIGH
        Q <= D; //non-blocking assignment statement
    assign notQ = ~Q;
endmodule