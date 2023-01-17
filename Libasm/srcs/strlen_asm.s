extern ___error
global _strlen_asm

section .text
_strlen_asm:
	xor rax, rax
	jmp boucle

boucle:
	mov sil, byte [rdi] ; tt en 8 bits
	cmp sil, 0
	je return
	inc rax
	inc rdi
	jmp boucle

return:
	ret