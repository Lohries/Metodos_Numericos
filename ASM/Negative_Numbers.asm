.global _start
_start:
    mov r0, #18
    mov r1, #7
    subs  r2, r1, r0 ;using the cpsr register