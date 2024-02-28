
section .text ;SHF_EXECINSTR
global _start
_start:
    mov edx, len
    mov ecx, msg
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov eax, 1
    int 0x80

sectoin .data ;SHF_WRITE
    msg db "Hello World", 0xa 
    len equ $ -msg