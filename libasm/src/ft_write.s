; ssize_t	ft_write(int fd, const void *buf, size_t count);

segment .text
global ft_write

ft_write:
	mov rax, 1
	syscall
	ret
