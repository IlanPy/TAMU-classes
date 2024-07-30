.globl lab04b

lab04b:
	SUB SP, SP, 0x10 //space the stack
	STUR LR, [SP, 0x8] //save LR on the stack
	STUR X0, [SP, 0x0] //save n on the stack
	SUBS XZR, X0, 0x1 //set flag for n and 1
	B.GE L1 //if n>=1, go to L1
	ORR X0, XZR, 0x1 //else, set return to 1
	ADD SP, SP, 0x10 //pop from stack
	BR LR //return
L1:
	SUB X0, X0, 0x1 //n = n-1
	BL lab04b //recursive fact(n-1)
bk_f:
	LDUR X1, [SP, 0x0] //restore n
	LDUR LR, [SP, 0x8] //resture return addr
	ADD SP, SP, 0x10 //pop from stack
	B my_mul // m = n*fact(n-1)
	BR LR //return 
