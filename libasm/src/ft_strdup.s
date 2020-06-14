segment .text
extern malloc
extern __errno
global ft_strdup

ft_strlen:
	mov rax, 0
compare:
	cmp byte [rdi+rax], 0
	jne inc_cnt
	ret
inc_cnt:
	inc rax
	jmp compare

ft_strdup:
	call ft_strlen
	call malloc WRT ..plt
	cmp rax, 0
	je error
	ret
error:
	mov rax, __errno
	ret

