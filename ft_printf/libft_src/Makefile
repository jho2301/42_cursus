SRCS = ${wildcard ./ft_*.c}
OBJS = ${SRCS:.c=.o}
NAME = libft.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -fPIC -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		${OBJS}
			ar rc ${NAME} ${OBJS}

