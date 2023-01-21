
global _ft_list_size

; int	ft_list_size(t_list *rdi);

_ft_list_size:
	xor rax, rax
	jmp boucle

boucle:
	cmp rdi, 0
	je return
	mov rdi, [rdi+8] ; rdi = *(rdi + 8) rdi->next
	inc rax
	jmp boucle

return:
	ret
