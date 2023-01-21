extern ___error
global _ft_write



section .text
_ft_write:
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



