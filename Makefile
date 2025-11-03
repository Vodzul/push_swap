NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
	arg_parsing.c \
	positive_stack.c \
	push_func.c \
	radix_sort.c \
	revr_func.c \
	rotate_func.c \
	small_cases.c \
	stack_utils.c \
	swap_func.c

LIBFT = libft/libft.a
INCLUDE = -Iinclude -Ilibft

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

libft/libft.a:
	$(MAKE) -C libft

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re