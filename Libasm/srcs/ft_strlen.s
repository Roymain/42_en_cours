extern ___error
global _ft_strlen

section .text
_ft_strlen:
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