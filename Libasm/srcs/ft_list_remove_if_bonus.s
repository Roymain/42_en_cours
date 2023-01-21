
global _ft_list_remove_if

; void	ft_list_remove_if(t_list **rdi, void *rsi, int (*rdx)(), void (*rcx)(void*));
;								begin		ref		cpm(elem, ref)	free

_ft_list_remove_if:
	cmp rsi, 0
	je return
	cmp rdi, 0
	je return
	cmp rcx, 0 ; verif 
	je return
	cmp rdx, 0 ; verif 
	je return
	mov r11, rdi 	; rdi ds r11
	mov rdi, [r11] 	;actu
	mov r12, 0 		;prev
	jmp boucle

boucle:
	cmp rdi, 0
	je return

	push rsp
	push rdi
	push rsi
	push rdx
	push rcx
	push r11
	push r12
	push r14
	push r15
	call rdx
	pop r15
	pop r14
	pop r12
	pop r11
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	pop rsp

	cmp rax, 0
	je delete
	mov r12, rdi
	mov rdi, [rdi+8]

	jmp boucle

delete:
	cmp r12, 0
	je deletefirst

	mov r15, [rdi+8]
	mov [r12+8], r15
	mov rdi, [rdi]

	push rsp
	push rdi
	push rsi
	push rdx
	push rcx
	push r11
	push r12
	push r14
	push r15
	call rcx
	pop r15
	pop r14
	pop r12
	pop r11
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	pop rsp

	mov rdi, [r12+8]
	jmp boucle


deletefirst:    ;r12 pre rdi actu
	mov r14, [rdi+8]
	mov rdi, [rdi]
	push rsp
	push rdi
	push rsi
	push rdx
	push rcx
	push r11
	push r12
	push r14
	push r15
	call rcx
	pop r15
	pop r14
	pop r12
	pop r11
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	pop rsp

	mov [r11], r14
	mov rdi, r14
	jmp boucle
return:
	ret
