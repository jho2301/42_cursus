SRCS = src/ft_strlen.s
OBJS = ${SRCS:.s=.o}
NAME = libasm.a

ASM = nasm
LINUX_FORMAT = -f elf64
MAC_FORMAT = -f macho64

RM = rm -f

.c.o:
			${ASM} ${LINUX_FORMAT} $< -o ${<:.s=.o}

all:		${NAME}

clean:
			${RM} ${OBJS}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}
			make clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		${OBJS}
			ar rc ${NAME} ${OBJS}

