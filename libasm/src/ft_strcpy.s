segment .text
global _ft_strcpy

_ft_strcpy:
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

