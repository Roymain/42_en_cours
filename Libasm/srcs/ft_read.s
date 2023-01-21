extern ___error
global _ft_read



section .text
_ft_read:
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



