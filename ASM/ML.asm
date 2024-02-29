.global _start
_start:
    ldr r0, =input ;storing the input 
    ldr r1, =weight ;storing the word
    mov r2, #3 ;bias
    mov r3, [r0]
    mul r3, r3, [r1]
    add r3, r3, [r0, #4]
    mul r3, r3, [r1, #4]
    add r3, r3, [r0, #8]
    mul r3, r3, [r1, #8]
    add r3, r3, [r0, #12]
    mul r3, r3, [r1, #12]
    add r3, r3, [r0, #16]
    mul r3, r3, [r1, #16]
    add r3, r3, r2
    





.data
input:
    .word  1.5, 3.5, 8.9, 10.5, 7.8

weight:
    .word 0.5, 1.5, 0.9, 0.5, 0.8
