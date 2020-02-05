##
## EPITECH PROJECT, 2020
## PSU_minishell1_2019
## File description:
## Makefile
##

SRC_DIR		=	src/

BUILTINS_DIR = src/builtins/

INC_DIR		=	include/

LIB_DIR		=	lib/my/

SRC			=	$(SRC_DIR)main.c				\
				$(SRC_DIR)get_next_line.c		\
				$(SRC_DIR)minishell.c			\
				$(SRC_DIR)get_bin_path.c		\
				$(SRC_DIR)get_env_path.c		\
				$(SRC_DIR)word_array.c			\
				$(BUILTINS_DIR)my_cd.c			\
				$(BUILTINS_DIR)my_env.c			\
				$(BUILTINS_DIR)my_setenv.c		\
				$(BUILTINS_DIR)my_unsetenv.c	\
				$(BUILTINS_DIR)my_exit.c

OBJ			=	$(SRC:.c=.o)

NAME		=	mysh_bonus

CFLAGS		+=	-Wall -Wextra -I./include -g

LDLFLAGS	+= -L $(LIB_DIR) -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) $(LDLFLAGS)

clean:
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(OBJ)

fclean:		clean
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(NAME)

re:	fclean all

run:	all
	./$(NAME)

debugs:	fclean all		gcc -o $(NAME) $(OBJ) $(LDLFLAGS) -g

.PHONY: all clean fclean re run debugs