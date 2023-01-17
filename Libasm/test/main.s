bits 64

    global    start
    section   .text
start:
    call       ft_write
    call       ft_write
    call       ft_write
    call       ft_write

    mov       rax, 0x02000001
    xor       rdi, rdi
    syscall 

ft_write:
    mov       rax, 0x02000004
    mov       rdi, 1
    mov       rsi, message
    mov       rdx, 14 + 1
    syscall
    ret

section   .data
message: db "Hello, World !", 10




global _write_asm

_write_asm:
    ; Ecriture des données dans le descripteur de fichier
    mov rax, 0x2000004
    syscall
    push rbp
    mov rbp, rsp
    
    mov rax, 0x2000004 ; write syscall
    mov rdi, 1 ; fd pour stdout
    mov rsi, [rsp + 16] ; str1
    mov rdx, 6
    syscall

    mov rax, 0x2000004 ; write syscall
    mov rdi, 1 ; fd pour stdout
    mov rsi, [rsp + 24]
    mov rdx, 6
    syscall
    pop rbp
    ret



