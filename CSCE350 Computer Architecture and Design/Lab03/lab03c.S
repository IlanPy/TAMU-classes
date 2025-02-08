.section .text
.globl lab03c

lab03c:
        ADRP X1, my_array
        ADD X1,X1, :lo12:my_array
        ADD X9, XZR, XZR //i = 0
	ADD X12, X0, XZR //j = input
loop:
	SUBS XZR, X9, #10 //set flag
	B.GE finish //i>=10
	LSL X10, X9, 0x3 //index i byte offset
	ADD X10, X10, X1 //A[i]
	STUR X12, [X10, 0] //Store j in A[i]
	ADD X12, X12, #1 //j++
	ADD X9, X9, #1 //i++
	B loop
finish:
        BR X30
 .section       .data
        my_array:    .space 0x50 //64*10/8=80
