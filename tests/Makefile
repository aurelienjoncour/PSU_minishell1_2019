##
## EPITECH PROJECT, 2020
## PSU_minishell1_2019
## File description:
## Makefile
##

TEST_DIR 	=	src/
SRC_DIR		=	../src/
INC_DIR		=	../include/
LIB_DIR		=	../lib/my

SRC		=	$(SRC_DIR)get_next_line.c			\
			$(SRC_DIR)builtins/my_unsetenv.c	\
			$(SRC_DIR)word_array.c				\
			$(SRC_DIR)get_env_path.c			\
			$(TEST_DIR)test_gnl.c				\
			$(TEST_DIR)test_unsetenv.c			\
			$(TEST_DIR)test_word_array.c		\
			$(TEST_DIR)test_getenvpath.c

OBJ		=	$(SRC:.c=.o)

NAME		=	test

CFLAGS		+=	-Wall -Wextra --coverage -I $(INC_DIR)

LDFLAGS		=	-L $(LIB_DIR) -lmy --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR) --no-print-directory
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)
		./$(NAME)
clean:
		rm -f $(OBJ)
		rm -f $(OBJ:.o=.gcno)
		rm -f $(OBJ:.o=.gcda)

fclean:		clean
			rm	-f	$(NAME)

re:		fclean all