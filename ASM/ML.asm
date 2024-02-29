.global _start
_start:
    ldr r0, =input ;storing the input 
    ldr r1, =word ;storing the word
    mov r2, #3 ;bias
    



.data
input:
    .word  1.5, 3.5, 8.9, 10.5, 7.8

weight:
    .word 0.5, 1.5, 0.9, 0.5, 0.8
