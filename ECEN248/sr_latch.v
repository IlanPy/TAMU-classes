`timescale 1ns / 1ps //delay unit is 1ns
`default_nettype none

module sr_latch(Q, notQ, En, S, R);
    /*port list*/
    output wire Q, notQ;
    input wire En, S, R;
    
    /*intermediate nets*/
    //nandSEN is the output of NAND(S, En)
    //nandREN is the output of NAND(R, En)
    wire nandSEN, nandREN;
    
    //delay of gate nand is 2ns
    nand #4 nand0(nandSEN, S, En);
    nand #4 nand1(nandREN, R, En);
    nand #4 nand2(Q, nandSEN, notQ);
    nand #4 nand3(notQ, nandREN, Q);

endmodule