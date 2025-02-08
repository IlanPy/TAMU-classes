`timescale 1ns / 1ps //delay unit is 1ns
`default_nettype none

module d_flip_flop(Q, notQ, Clk, D);
    //declare all ports
    output wire Q, notQ; //outputs of slave latch
    input wire Clk, D;
    
    /*intermediate nets*/
    wire notClk, notNotClk;
    wire Qm; //output of master latch
    //notQm is used in instantiation
    //but left unconnected
    wire notQm;
    
    //instantiate the NOT gates, add 2ns delay
    not #2 not0(notClk, Clk);
    not #2 not1(notNotClk, notClk);
    
    //instantiate the D-latches
    d_latch d_latch0(Qm, notQm, notClk, D);
    d_latch d_latch1(Q, notQ, notNotClk, Qm);

endmodule