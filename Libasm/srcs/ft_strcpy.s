
global _ft_strcpy

section .text
_ft_strcpy:
	mov rax, rdi
	jmp boucle

boucle:
	mov r15b, byte [rsi]
	mov  byte [rdi], r15b
	cmp r15b, 0
	je return
	inc rdi
	inc rsi
	jmp boucle
	
return:
	ret