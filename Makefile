NAME = push_swap
FILES = push_swap.c linked_list_utils.c indexation.c algorithm.c instructions.c parsing.c libft.c 
OBJ = $(FILES:.c=.o)
CC = cc
CFLAGS = 

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
