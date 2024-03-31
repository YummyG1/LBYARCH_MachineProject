;assembly part using x84-x64

section .data
section .text
bits 64 
default rel  ; to handle adress relocation


global asmfunc

asmfunc:
	mulss xmm0, xmm1;
	addss xmm0, xmm2;
	ret