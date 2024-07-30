module NextPClogic(NextPC, CurrentPC, SignExtImm64, Branch, ALUZero, Uncondbranch);
	/* module definition from lab */
	input [63:0] CurrentPC, SignExtImm64;
	input Branch, ALUZero, Uncondbranch;
	output reg [63:0] NextPC;
	/* write your code here */
	always @(*) begin
		if(Uncondbranch || (Branch && ALUZero)) begin
			// when we branch, shift offset by 2 to get byte offset as each instr is 4 bytes
			NextPC = CurrentPC + (SignExtImm64 <<< 2);
		end else begin
			//default is next instr (4 byte offset)
			NextPC = CurrentPC + 4;
		end
	end
endmodule
