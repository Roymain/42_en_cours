extern ___error
global _write_asm



section .text
_write_asm:
    mov rax, 0x2000004
    syscall
    jc error_handle
    ret



error_handle: 
    mov rdi, rax
    call ___error
    mov [rax], rdi
    mov rax, -1
    ret



