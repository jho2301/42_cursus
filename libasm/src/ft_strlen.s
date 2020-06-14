segment .text

global ft_strlen

ft_strlen:
	mov rax, 0
compare:
	cmp byte [rdi+rax], 0
	jne inc_cnt
	ret
inc_cnt:
	inc rax
	jmp compare
