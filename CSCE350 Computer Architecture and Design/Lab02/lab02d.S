.section .text
.globl lab02d 

lab02d:
       ADRP X3, myvalue //Load all  but lower 12 bits of the addr of myvalue
       ADD X3,X3, :lo12:myvalue //Load lower 12 bits of the addr of myvalue
       ADD X2, X0, 0x3e8 //Add 1000 to the argument passed (stored in X0)
       STUR X2, [X3,0] //Store the value into myvalue
       ADD X0, X3, XZR //Set return register (X0) to myvalue
       BR X30 //return

.section .data

myvalue:
.quad 0 

