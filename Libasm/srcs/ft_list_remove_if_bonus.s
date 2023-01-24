extern _free

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
	mov r8, 0    ;old
	push rdi
	mov rdi, [rdi]
	mov r15, rdi   ;save maillon
	jmp boucle

boucle:
	cmp rdi, 0
	je return
	mov rdi, [rdi]
	push rcx
	call rdx
	pop rcx
	cmp rax, 0
	je delete

	mov r8, r15
	mov rdi, [r15 + 8]
	mov r15, rdi   ;save maillon

 	jmp boucle

delete:
	;pop r14
	;ret
	cmp r8, 0
	je return
	push rcx ; aa
	call rcx
	pop rcx  ;aa
	push rdi
	push rsi
	push rdx
	;push rcx
	push r15
	push r8
	push rsp

	mov rdi, r15
	call _free

	pop rsp
	pop r8
	pop r15
	;pop rcx
	pop rdx
	pop rsi
	pop rdi


	mov rdi, [r15 + 8]
	mov r15, rdi
	mov [r8 + 8], rdi



	jmp boucle


deletefirst:
	pop r14
	ret
return:
	pop r14
	ret
