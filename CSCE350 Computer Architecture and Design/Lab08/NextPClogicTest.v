module NextPClogic_v;

    task passTest;
        input [63:0] actualOut, expectedOut;
        input [255:0] testType;
        inout [7:0] passed;
        
        if (actualOut == expectedOut) begin
            $display ("%s passed", testType);
            passed = passed + 1;
        end 
	else begin
            $display ("%s failed: %d should be %d", testType, actualOut, expectedOut);
        end
    endtask

    task allPassed;
        input [7:0] passed;
        input [7:0] numTests;
        
        if (passed == numTests) begin
            $display ("All tests passed");
        end else begin
            $display("Some tests failed");
        end
    endtask

    // Inputs
    reg [63:0] CurrentPC, SignExtImm64;
    reg Branch, ALUZero, Uncondbranch;
    reg [7:0] passed;

    // Outputs
    wire [63:0] NextPC;

    initial //This initial block used to dump all wire/reg values to dump file
        begin
                $dumpfile("NextPClogic.vcd");
                $dumpvars(0,NextPClogic_v);
        end

    // Instantiate the Device Under Test (DUT)
    NextPClogic dut (
        .NextPC(NextPC),
        .CurrentPC(CurrentPC), 
        .SignExtImm64(SignExtImm64), 
        .Branch(Branch),
        .ALUZero(ALUZero),
        .Uncondbranch(Uncondbranch)
    );

    initial begin 
        // Initialize Inputs
        CurrentPC =64'b0;
        SignExtImm64=64'b0;
        Branch=1'b0;
        ALUZero=1'b0;
        Uncondbranch=1'b0;
        passed = 0;

        // Test cases: Normal
        #30; passTest(NextPC, 64'h0000000000000004, "Normal Progression 1", passed); // normal +4 on PC
        #30 CurrentPC=64'h1234567890ABCDEF; SignExtImm64=64'h0000000000000008; #30; passTest(NextPC, 64'h1234567890ABCDF3, "Normal Progression 2", passed); // normal +4 on PC


	// Unconditional branching
	#30 CurrentPC=64'h0; SignExtImm64=64'h1234567890ABCDEF;  Uncondbranch=1'b1;
 #30; passTest(NextPC, 64'h48D159E242AF37BC, "Unconditional Branching 1", passed); // PC+ Sign*4 on PC
        #30 CurrentPC=64'h1234567890ABCDEF; #10; passTest(NextPC, 64'h5B05B05AD35B05AB, "Unconditional Branch 2", passed); //  // PC+ Sign*4 on PC


 // Unsuccessful branching
	#30 CurrentPC=64'h0; Branch=1'b1; ALUZero=1'b0;  Uncondbranch=1'b0;
 #10; passTest(NextPC, 64'h0000000000000004, "Unsuccessful Branching 1", passed); // PC+4 on PC
        #30 CurrentPC=64'h1234567890ABCDEF; #30; passTest(NextPC, 64'h1234567890ABCDF3, "Unsuccessful Branching 2", passed); //  // PC +4 on PC

 // Successful branching
	#30 CurrentPC=64'h0;  Branch=1'b1; ALUZero=1'b1;
 #30; passTest(NextPC, 64'h48D159E242AF37BC, "Successful Branching 1", passed); // PC+ Sign*4 on PC
        #30 CurrentPC=64'h1234567890ABCDEF; #30; passTest(NextPC, 64'h5B05B05AD35B05AB, "Unconditional Branch 2", passed); //  // PC+ Sign*4 on PC
             

                #30;
        allPassed(passed, 8);
    end
endmodule
