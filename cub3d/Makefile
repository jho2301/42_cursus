CC = gcc
CFLAGS =	 -I.src/run_game/minilibx
LINUXLIB =	-lmlx -lXext -lX11 -l bsd
3W = -Wextra -Wall -Werror

NAME= cub3D

SRC = src/main.c $(wildcard src/*/*.c) $(wildcard src/*/draw/*.c) $(wildcard src/*/handle_input/*.c) $(wildcard src/*/user_info/*.c)
OBJ = $(SRC:.c=.o)
LIBFT = src/util/libft.a
DEBUG = -g

all	:$(NAME)

$(NAME)	:	$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(LINUXLIB) -fPIE $(DEBUG) $(3W)

clean	:
				rm -f $(NAME) $(OBJ)

re	: 		clean all
