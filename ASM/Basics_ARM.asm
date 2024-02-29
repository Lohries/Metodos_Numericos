.global _start
_start:
	ldr r0, =list  ;ldr(load register)
	ldr r1,[r0]
	ldr r1, [r0, #4]  
	

.data 
list:
	.word 4, 6, 7, 8, 9
	
	
	