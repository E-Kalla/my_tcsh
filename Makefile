##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Make bsq
##

SRC		=	./src/main.c	\
			./src/my_pustr.c	\
			./src/my_putchar.c  \
			./src/my_put_nbr.c  \
			./src/cd.c  \
			./src/find.c    \
			./src/exec.c    \
			./src/shell.c   \
			./src/my_strcpy.c   \
			./src/my_strcmp.c   \
			./src/my_strlen.c   \
			./src/my_getnbr.c   \
			./src/get_arg.c     \
			./src/str_to_tab.c  \
			./src/my_strncpy.c  \
			./src/sigsev.c  \
			./src/command.c     \
			./src/my_strcat.c   \
			./src/bin.c \
			./src/get_tab.c \
			./src/clean_str.c

OBJ 	= 	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS  =   -Iinclude -g3

$(NAME) : $(OBJ)
		gcc -o $(NAME) $(OBJ)
all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:
		fclean all
