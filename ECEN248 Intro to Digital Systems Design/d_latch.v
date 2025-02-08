`timescale 1ns / 1ps //delay unit is 1ns
`default_nettype none

module d_latch(Q, notQ, En, D);
    /*port list*/
    output wire Q, notQ;
    input wire En, D;
    
    /*intermediate nets*/
    //nandNOTDEN is the output of NAND(notD, En)
    //nandDEN is the output of NAND(D, En)
    wire notD, nandNOTDEN, nandDEN;
    
    //delay of gate nand and inv is 2 ns
    not #2 not0(notD, D);
    nand #2 nand0(nandNOTDEN, notD, En);
    nand #2 nand1(nandDEN, D, En);
    nand #2 nand2(Q, nandDEN, notQ);
    nand #2 nand3(notQ, nandNOTDEN, Q);
    
endmodule