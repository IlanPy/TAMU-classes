module Mux21(out, in, sel); //declare half adder module
	input [1:0] in; //input signals I0 & I1
	input sel; //select input
	output out; //output of mux
	wire notsel, and0, and1; //intermediate wires
	not n0(notsel, sel); //not select input
	and a0(and0, notsel, in[0]); //and input 0 with not sel
	and a1(and1, sel, in[1]); //and input 1 with sel
	or o0(out, and0, and1); //pick one input
endmodule //end of module
