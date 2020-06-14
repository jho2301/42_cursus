SRCS =	src/ft_strlen.s	\
		src/ft_strcpy.s	\
		src/ft_strcmp.s	\
		src/ft_write.s	\
		src/ft_read.s	\
		src/ft_strdup.s
OBJS =	${SRCS:.s=.o}
NAME =	libasm.a

ASM =	nasm
LINUX_FORMAT =	-f elf64
MAC_FORMAT =	-f macho64

RM =	rm -f

.s.o:		.s
			${ASM} ${LINUX_FORMAT} $< -o $@

all:		${NAME}

clean:
			${RM} ${OBJS}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

