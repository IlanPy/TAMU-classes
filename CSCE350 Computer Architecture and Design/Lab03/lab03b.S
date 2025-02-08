.section .text
.globl lab03b

lab03b:
        ADRP X0, UIN
        ADD X0,X0, :lo12:UIN
	LDUR X10, [X0, 0] //X10 = UIN
        ADD X9, XZR, XZR //i = 0
loop:
	SUBS XZR, X9, #10 //set flag
	B.GE finish //i>=10
	SUB X10, X10, #1 //UIN = UIN-1
	ADD X9, X9, #1 //i++
	B loop
finish:
	STUR X10, [X0, 0] //store new val in UIN
	ADD X0, X10, XZR //set return reg (X0)
        BR X30 //return
 .section       .data
        UIN:    .word 0x22 //UIN:232007587; sum=34
