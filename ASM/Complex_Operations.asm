.global _start
_start:
    ;Modeling this math expressions 2 * a + b + c * 5 - d
    mov r0, #4 ;a
    mov r1, #5 ;b
    mov r2, #9 ;c
    mov r3, #10 ;d

    mul r4, #2, r0
    add r4, r4, r1
    add r5, #5, r2
    add r6, r4, r5
    
    
    