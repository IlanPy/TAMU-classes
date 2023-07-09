`timescale 1ns / 1ps //delay unit is 1ns
`default_nettype none

module d_latch_behavioral(
    output reg Q, //driven with a behavioral statement
    output wire notQ, //driven with a dataflow statement
    input wire D, En //wires can drive regs
    );
    
    /*(describe hevior of D-latch*/
    always@(En or D)
        if(En) //if En != 1'b0
            Q = D;
        //else Q = Q; //this is implied
    assign notQ = ~Q; //regs can drive wires

endmodule