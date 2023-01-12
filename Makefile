NAME = push_swap.a
files = push_swap.c
OBJ = $(NAME.c = .o)
CC = cc
CFLAGS = -Wall -Wflag -Werror -I push_swap.h

all: $(NAME)
$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)
%.o : %.c push_swap.h
	%(CC) -c $(CFLAGS) $<
clean :
	rm -rf $(OBJ)
fclean :
	rm -rf $(NAME)
re: fclean all
