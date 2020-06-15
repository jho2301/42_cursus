segment .text
extern _malloc, ___error
global _ft_strdup

ft_strlen:
	mov rax, 0
compare:
	cmp byte [rdi+rax], 0
	jne inc_cnt
	ret
inc_cnt:
	inc rax
	jmp compare

ft_strcpy:
	mov rax, 0
continue:
	cmp byte[rsi+rax], 0
	je break
	mov cl, byte[rsi+rax]                                                        
	
	mov byte[rdi+rax], cl
	inc rax
	jmp continue
break:
	mov byte[rdi+rax], 0
	mov rax, rdi
	ret

_ft_strdup:
	call ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je error
	mov rdi, rax
	pop rsi
	call ft_strcpy
	ret
error:
	push rax
	call ___error
	mov rbx, 0
	pop rbx
	mov [rax], rbx
	mov rax, 0
	ret

