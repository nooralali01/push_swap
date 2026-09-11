NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = push_swap.c \
      stack_init.c stack_push.c stack_swap.c stack_rotate.c stack_reverse.c \
      input.c input_utils.c split_words.c simple_sort.c disorder.c \
	  selector.c flags.c extra.c complex_sort.c medium_sort.c bench.c bench_ops.c \
	  runtime_init.c  simple.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re