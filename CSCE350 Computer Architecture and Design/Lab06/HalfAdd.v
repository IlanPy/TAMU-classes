module HalfAdd(Cout, Sum, A, B); //declare half adder module
	input A, B; //input signals A & B
	output Cout, Sum; //outputs sum & carry
	wire nand0, nand1, nand2; //intermediate wires
	nand n0(nand0, A, B); //first nand A & B
	nand n1(nand1, A, nand0); //second nand gate
	nand n2(nand2, nand0, B); //third nand gate
	nand n3(Sum, nand1, nand2); //fourth nand to get sum
	nand n4(Cout, nand0, nand0); //fifth nand to get carry
endmodule //end of module
