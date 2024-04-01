.global _start
_start:
    mov r0, #18
    mov r1, #7
    subs  r2, r1, r0 ;using the cpsr register

    mov r3, #0xFFFFFFFF
    mov r4, #7
    adc r5, r3, r4 ;using the adc method to carry more data into the register


    



