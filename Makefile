NAME = push_swap
FILES = push_swap.c linked_list_utils.c indexation.c algorithm.c instructions_a.c case3_case5.c filling_list_func.c parsing_utils.c instructions_b.c parsing.c libft.c algorithm_utils.c
OBJ = $(FILES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I push_swap.h

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $<
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re: fclean all
