.global _start
_start:
	ldr r0, =list  ;ldr(load register)
	ldr r1,[r0] ;in the register r1, storing some value of the memory store in the r0
	ldr r2, [r0, #4]  ;loading in the register r1 the value 4 of the space memory that contains the list store the second parameter is to move in the space of the list
    ldr r3, [r0, #8]  
	ldr r4, [r0, #12]  

.data 
list:
	.word 4, 6, 7, 8, 9


	
	
	