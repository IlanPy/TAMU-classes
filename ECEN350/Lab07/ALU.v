`define AND   4'b0000
`define OR    4'b0001
`define ADD   4'b0010
`define SUB   4'b0110
`define PassB 4'b0111


module ALU(BusW, Zero, BusA, BusB, ALUCtrl);
    
    parameter n = 64;

    output  [n-1:0] BusW;
    input   [n-1:0] BusA, BusB;
    input   [3:0] ALUCtrl;
    output  Zero;
    
    reg     [n-1:0] BusW;
    
    always @(ALUCtrl or BusA or BusB) begin
        case(ALUCtrl)
            `AND: begin
                BusW = BusA & BusB; //and inputs
            end
	    `OR: begin
		BusW = BusA | BusB; //or inpits
	    end
	    `ADD: begin
		BusW = BusA + BusB; //add inputs
	    end
	    `SUB: begin
		BusW = BusA - BusB; //subtract inputs
	    end
	    `PassB: begin
		BusW = BusB; //pass input b
	    end
	    default: begin
		BusW = 0; //default set output to 0
	    end
        endcase
    end

    assign Zero = (BusW == 0); //zero = 1 if bus = 0, zero = 0 else
endmodule
