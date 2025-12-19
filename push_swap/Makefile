CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = push_swap.c push_swap_utils.c data_utils.c free_content.c \
	console_output.c stack_utils.c print_stack.c \
	sorting_operators/swapping_op.c \
	sorting_operators/push_op.c \
	sorting_operators/rotate_op.c \
	sorting_operators/reverse_rotate_op.c \
	sorting_algorithms/simple_sorting.c \
	sorting_algorithms/sort_nums.c \
	sorting_algorithms/sorting_aux.c \
	sorting_algorithms/sorting_aux2.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
HEADERS = push_swap.h \
	libft/libft.h
NAME = push_swap

all: $(NAME)

libft:
	make -C libft all bonus

$(LIBFT): libft/Makefile
	make -C libft all bonus

# Enlazado .o a ejecutable
$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compilación archivos .c a .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft