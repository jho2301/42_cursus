SRCS = ${wildcard ./*/*.c}
OBJS = ${SRCS:.c=.o}
NAME = libft.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -fPIC -c $< -o ${<:.c=.o}

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

