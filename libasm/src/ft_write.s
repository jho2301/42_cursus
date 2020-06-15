; ssize_t	ft_write(int fd, const void *buf, size_t count);

segment .text
global _ft_write
extern ___error

_ft_write:
	mov rax, 0x2000004
	syscall
	cmp rax, 0
	jl error
	ret
error:
	push rax
	call ___error
	pop rbx
	mov [rax], rbx
	mov rax, -1
	ret
