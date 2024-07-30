module Decode24 ( out , in ) ;
	input [ 1 : 0 ] in ;
	output [ 3 : 0 ] out ;
	reg out;

	always @(in) //always block triggered by in
	begin //begin always block
		if(in == 2'b00) out = 4'b0001; //if-else block to decode in
		else if(in == 2'b01) out = 4'b0010; //produce one-hot output
		else if(in == 2'b10) out = 4'b0100;
		else if(in == 2'b11) out = 4'b1000;
	end //end of always block
endmodule //end of module
