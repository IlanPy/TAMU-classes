module SignExtender(BusImm, Imm26, Ctrl); 
  output [63:0] BusImm; 
  input [25:0] Imm26; 
  input [2:0] Ctrl; //canged to 3 bits

  wire extBit;

  //set MSB as extending bit based on ctrl
  assign extBit = (Ctrl == 3'b000 ? 1'b0 : //I (zero extended)
	 Ctrl == 3'b001 ? Imm26[20] : //D
	 Ctrl == 3'b010 ? Imm26[25] : //B
	 Ctrl == 3'b011 ? Imm26[23] : //Ctrl == 2'b11, CB 
 	 1'b0); //default

  //Sign extend MSB based on ctrl
  assign BusImm = (Ctrl == 3'b000 ? {{52{extBit}}, Imm26[21:10]} : //I
	  Ctrl == 3'b001 ? {{55{extBit}}, Imm26[20:12]} : //D
	  Ctrl == 3'b010 ? {{38{extBit}}, Imm26[25:0]} : //B
	  Ctrl == 3'b011 ? {{45{extBit}}, Imm26[23:5]} : //Ctrl == 2'b11, CB
	  Ctrl == 3'b100 ? (Imm26[22:21] == 2'b00 ? {48'b0, Imm26[20:5]} : //shift 16*0 bits
	 		    Imm26[22:21] == 2'b01 ? {32'b0, Imm26[20:5], 16'b0} : //shift 16*1 bits
			    Imm26[22:21] == 2'b10 ? {16'b0, Imm26[20:5], 32'b0} : //shift 16*2 bits
			    Imm26[22:21] == 2'b11 ? {Imm26[20:5], 48'b0} : //shift 16*3 bits
		    	    64'b0) : //default
	    		64'b0); //default 
endmodule
