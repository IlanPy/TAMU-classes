`timescale 1ns / 1ps //specify 1ns for each delay unit
`default_nettype none

/* This module is a syncrhonous circuit for our ripple carry adder */

module adder_synchronous(Carry_reg, Sum_reg, Clk, A, B);

    /* Output ports are regs!!! why? well they need to be able to
       hold state */
    output reg Carry_reg;
    output reg [1:0] Sum_reg;
    
    /* Inputs are still wires */
    input wire Clk;
    input wire [1:0] A, B;
    
    /*intermediate nets*/
    reg [1:0] A_reg, B_reg; //will use these as 2-bit registers
    wire Carry; //need this to connect to the registers described below
    wire [1:0] Sum;
    
    /*instantiate 2-bit adder*/
    adder_2bit adder_2bit0(Carry, Sum, A, B);
    
    /*this behavioral block describes two 2-bit registers*/
    /*registers are grouped flip-flops*/
    always@(posedge Clk) //trigger one positive edge of the clock
        begin //needed because two statements within always block
            A_reg <= A; //we use non-blocking assignment because we want
            B_reg <= B; //these two statements to happen concurrently
        end
        
    /*describe registers for the result*/
    always@(posedge Clk)
        begin
            Carry_reg <= Carry; 
            Sum_reg <= Sum;
        end

endmodule