extern ___error
global _read_asm



section .text
_read_asm:
    mov rax, 0x2000003
    syscall
    jc error_handle
    ret



error_handle: 
    mov rdi, rax
    call ___error
    mov [rax], rdi
    mov rax, -1
    ret



