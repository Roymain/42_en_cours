
global _ft_strcmp

section .text
_ft_strcmp:
	xor rax, rax
	jmp boucle

boucle:
	mov r14b, byte [rdi]
	mov r15b, byte [rsi]
	cmp r14b, r15b
	jne return
	cmp r14b, 0
	je return
	inc rdi
	inc rsi
	jmp boucle

setneg:
	mov rax, -1
	ret

setpos:
	mov rax, +1
	ret
	
return:
	cmp r14b, r15b
	jl setneg
	jg setpos
	ret