`timescale 1ns / 1ps
`define STRLEN 15

module SignExtenderTest_v;

        task passTest;
                input [63:0] actualBusImm, expectedBusImm;
                input [`STRLEN*8:0] testType;
                inout [7:0] passed;

                if(actualBusImm == expectedBusImm) begin $display ("%s passed", testType); passed = passed + 1; end
                else $display ("%s failed: %d should be %d", testType, actualBusImm, expectedBusImm);
        endtask

        task allPassed;
                input [7:0] passed;
                input [7:0] numTests;

                if(passed == numTests) $display ("All tests passed");
                else $display("Some tests failed");
        endtask

        task stim;
                input [25:0] newImm26;
                input [1:0] newCtrl;
                output [25:0] setImm26;
                output [1:0] setCtrl;

                begin
                        #90;
                        setImm26 = newImm26;
                        setCtrl = newCtrl;
                end
        endtask

        // Inputs
        reg [25:0] Imm26;
        reg [1:0] Ctrl;
        reg [11:0] passed;

        // Outputs
        wire [63:0] BusImm;

        initial //This initial block used to dump all wire/reg values to dump file
        begin
                $dumpfile("SignExtenderTest.vcd");
                $dumpvars(0,SignExtenderTest_v);
        end

        // Instantiate the Unit Under Test (UUT)
        SignExtender uut (
                .BusImm(BusImm),
                .Imm26(Imm26),
                .Ctrl(Ctrl)
        );

        initial begin
                // Initialize Inputs
                Imm26 = 0;
                Ctrl = 0;
                passed = 0;

                stim(0, 2'b00, Imm26, Ctrl); #10; passTest(BusImm, 64'h0000000000000000, "I-type 0", passed);
                stim(26'b00001000000000001111111111, 2'b00, Imm26, Ctrl); #10; passTest(BusImm, 64'h800, "I-type neg", passed);
                stim(26'b11110111111111110000000000, 2'b00, Imm26, Ctrl); #10; passTest(BusImm, 64'h00000000000007FF, "I-type pos", passed);
                stim(0, 2'b01, Imm26, Ctrl); #10; passTest(BusImm, 64'h0000000000000000, "D-type 0", passed);
                stim(26'b00000100000000111111111111, 2'b01, Imm26, Ctrl); #10; passTest(BusImm, 64'hFFFFFFFFFFFFFF00, "D-type neg", passed);
                stim(26'b11111011111111000000000000, 2'b01, Imm26, Ctrl); #10; passTest(BusImm, 64'h00000000000000FF, "D-type pos", passed);
                stim(0, 2'b10, Imm26, Ctrl); #10; passTest(BusImm, 64'h0000000000000000, "B-type 0", passed);
                stim(26'b10000000000000000000000000, 2'b10, Imm26, Ctrl); #10; passTest(BusImm, 64'hFFFFFFFFFE000000, "B-type neg", passed);
		stim(26'b01111111111111111111111111, 2'b10, Imm26, Ctrl); #10; passTest(BusImm, 64'h0000000001FFFFFF, "B-type pos", passed);
		stim(0, 2'b11, Imm26, Ctrl); #10; passTest(BusImm, 64'h0000000000000000, "D-type 0", passed);
		stim(26'b00100000000000000000011111, 2'b11, Imm26, Ctrl); #10; passTest(BusImm, 64'hFFFFFFFFFFFC0000, "D-type neg", passed);
                stim(26'b11011111111111111111100000, 2'b11, Imm26, Ctrl); #10; passTest(BusImm, 64'h000000000003FFFF, "D-type pos", passed);
		#10;

                allPassed(passed, 12);
        end

endmodule
