`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:02:47 03/05/2009
// Design Name:   ALU
// Module Name:   E:/350/Lab8/ALU/ALUTest.v
// Project Name:  ALU
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ALU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

`define STRLEN 32
module ALUTest_v;

	task passTest;
		input [64:0] actualOut, expectedOut;
		input [`STRLEN*8:0] testType;
		inout [7:0] passed;
	
		if(actualOut == expectedOut) begin $display ("%s passed", testType); passed = passed + 1; end
		else $display ("%s failed: %x should be %x", testType, actualOut, expectedOut);
	endtask
	
	task allPassed;
		input [7:0] passed;
		input [7:0] numTests;
		
		if(passed == numTests) $display ("All tests passed");
		else $display("Some tests failed");
	endtask

	// Inputs
	reg [63:0] BusA;
	reg [63:0] BusB;
	reg [3:0] ALUCtrl;
	reg [7:0] passed;

	// Outputs
	wire [63:0] BusW;
	wire Zero;

	initial //This initial block used to dump all wire/reg values to dump file
        begin
                $dumpfile("ALUTest.vcd");
                $dumpvars(0,ALUTest_v);
        end

	// Instantiate the Unit Under Test (UUT)
	ALU uut (
		.BusW(BusW), 
		.Zero(Zero), 
		.BusA(BusA), 
		.BusB(BusB), 
		.ALUCtrl(ALUCtrl)
	);

	initial begin
		// Initialize Inputs
		BusA = 0;
		BusB = 0;
		ALUCtrl = 0;
		passed = 0;

                // Here is one example test vector, testing the ADD instruction:
		{BusA, BusB, ALUCtrl} = {64'h1234, 64'hABCD0000, 4'h2}; #40; passTest({Zero, BusW}, 65'h0ABCD1234, "ADD 0x1234,0xABCD0000", passed);
		//Reformate and add your test vectors from the prelab here following the example of the testvector above.	
		{BusA, BusB, ALUCtrl} = {64'h218, 64'h329, 4'h0}; #40; passTest({Zero, BusW}, 64'h208, "AND 0x218,0x329", passed);

{BusA, BusB, ALUCtrl} = {64'h3299, 64'h1020, 4'h0}; #40; passTest({Zero, BusW}, 65'h1000, "AND 0x3299,0x1020", passed);

{BusA, BusB, ALUCtrl} = {64'h20, 64'h4500, 4'h0}; #40; passTest({Zero, BusW}, {1'b1, 64'h0}, "AND 0x20,0x4500", passed);

{BusA, BusB, ALUCtrl} = {64'h290D, 64'h2DEF, 4'h1}; #40; passTest({Zero, BusW}, 65'h2DEF, "OR 0x290D,0x2DEF", passed);

{BusA, BusB, ALUCtrl} = {64'h328C, 64'hA3E4, 4'h1}; #40; passTest({Zero, BusW}, 65'hB3EC, "OR 0x328C,0xA3E4", passed);

{BusA, BusB, ALUCtrl} = {64'h29D0, 64'h0, 4'h1}; #40; passTest({Zero, BusW}, 65'h29D0, "OR 0x29D0,0x0", passed);

{BusA, BusB, ALUCtrl} = {64'h8AB, 64'hB78, 4'h2}; #40; passTest({Zero, BusW}, 65'h1423, "ADD 0x8AB,0xB78", passed);

{BusA, BusB, ALUCtrl} = {64'h0, 64'h1232, 4'h2}; #40; passTest({Zero, BusW}, 65'h1232, "ADD 0x0,0x1232", passed);

{BusA, BusB, ALUCtrl} = {64'h9ABC, 64'h1234, 4'h2}; #40; passTest({Zero, BusW}, 65'hACF0, "ADD 0x9ABC,0x1234", passed);

{BusA, BusB, ALUCtrl} = {64'hDEF, 64'hABC, 4'h6}; #40; passTest({Zero, BusW}, 65'h333, "SUB 0xDEF,0xABC", passed);

{BusA, BusB, ALUCtrl} = {64'hABC, 64'hDEF, 4'h6}; #40; passTest({Zero, BusW}, 65'hfffffffffffffccd, "SUB 0xABC,0xDEF", passed);

{BusA, BusB, ALUCtrl} = {64'h197D, 64'h92, 4'h6}; #40; passTest({Zero, BusW}, 65'h18EB, "SUB 0x197D,0x92", passed);

{BusA, BusB, ALUCtrl} = {64'h28D, 64'h3, 4'h7}; #40; passTest({Zero, BusW}, 65'h3, "PassB 0x28D,0x3", passed);

{BusA, BusB, ALUCtrl} = {64'h394, 64'h29D, 4'h7}; #40; passTest({Zero, BusW}, 65'h29D, "PassB 0x394,0x29D", passed);

{BusA, BusB, ALUCtrl} = {64'h0, 64'h20EF, 4'h7}; #40; passTest({Zero, BusW}, 65'h20EF, "PassB 0x0,0x20EF", passed);


		allPassed(passed, 16);
	end
      
endmodule

