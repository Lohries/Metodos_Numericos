.global _start
_start:
	ldr r0, =list  ;ldr(load register)
	ldr r1,[r0] ;in the register r1, storing some value of the memory store in the r0
	ldr r1, [r0, #4]  ;loading in the register r1 the value 4 of the space memory that contains the list store 
	

.data 
list:
	.word 4, 6, 7, 8, 9

list = [4, 6, 7, 8, 9]
list[r0+1]
	
	
	