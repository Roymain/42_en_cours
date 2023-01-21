extern _malloc
global _ft_list_push_front

; void	ft_list_push_front(t_list **rdi, void *rsi);
_ft_list_push_front:
	cmp rsi, 0
	je return
	cmp rdi, 0
	je return

	push rsp
	push rdi
	push rsi

	mov rdi, 16
	call _malloc
	cmp rax, 0

	pop rsi
	pop rdi
	pop rsp

	je return

	
	mov [rax], rsi
	mov rsi, [rdi]
	mov [rax+8], rsi
	mov [rdi], rax
	ret

return:
	ret