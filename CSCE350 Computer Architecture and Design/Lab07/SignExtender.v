module SignExtender(BusImm, Imm26, Ctrl); 
  output [63:0] BusImm; 
  input [25:0] Imm26; 
  input [1:0] Ctrl; 

  wire extBit;

  //set MSB as extending bit based on ctrl
  assign extBit = (Ctrl == 2'b00 ? 1'b0 : //I (zero extended)
	 Ctrl == 2'b01 ? Imm26[20] : //D
	 Ctrl == 2'b10 ? Imm26[25] : //B
	 Imm26[23]); //Ctrl == 2'b11, CB 

  //Sign extend MSB based on ctrl
  assign BusImm = (Ctrl == 2'b00 ? {{52{extBit}}, Imm26[21:10]} : //I
	  Ctrl == 2'b01 ? {{55{extBit}}, Imm26[20:12]} : //D
	  Ctrl == 2'b10 ? {{38{extBit}}, Imm26[25:0]} : //B
	  {{45{extBit}}, Imm26[23:5]}); //Ctrl == 2'b11, CB

endmodule
