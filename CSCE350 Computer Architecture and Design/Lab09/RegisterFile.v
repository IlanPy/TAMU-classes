module RegisterFile(BusA, BusB, BusW, RA, RB, RW, RegWr, Clk);
    output reg [63:0] BusA;
    output reg [63:0] BusB;
    input [63:0] BusW;
    input [4:0] RW;
    input [4:0] RA, RB;
    input RegWr;
    input Clk;
    reg [63:0] registers [31:0];

   // updating inputs whenever they change (not only at the posedge)
   // If RA = 31, keep bus at 0
    always @ (*) begin
        BusA = (RA == 5'b11111) ? 64'b0 : registers[RA]; // output 1
        BusB = (RB == 5'b11111) ? 64'b0 : registers[RB]; // output 2
    end

    // outputs and writing back
    always @ (negedge Clk) begin
        if(RegWr && RW != 5'b11111) // dont want to change X31 to be not zero
            registers[RW] <= #3 BusW; // updating writeback register
    end
endmodule
