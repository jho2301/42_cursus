SRCS 		= ${wildcard ./srcs/*.c}
OBJS 		= ${SRCS:.c=.o}
RM 			= rm -f
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
NAME		= libftprintf.a
LIBFT_DIR	= libft_src
LIBFT_LIB	= libft.a
FLAGS		= -Wall -Wextra -Werror
INCS		= .
.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}
$(NAME): ${OBJS}
	make all -C $(LIBFT_DIR)/
	cp $(LIBFT_DIR)/$(LIBFT_LIB) $(NAME)
	ar -rcs $(NAME) $(OBJS)
all: $(NAME)

clean:
	${RM} $(OBJS) ./srcs/main.o
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

bonus: all

test:  ${OBJS}
		make -C ./${LIBFT_DIR}
		${CC} ${FLAGS} -c main.c -o ./srcs/main.o -I${INCS}
		${CC} ${FLAGS} ${OBJS} ./srcs/main.o -o a.out -L ${LIBFT_DIR} -lft
		make clean

