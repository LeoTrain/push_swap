NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c srcs/sort/small_sort.c srcs/sort/chunk_sort.c\
	   srcs/utils/stack_utils.c srcs/utils/errors.c srcs/utils/ft.c srcs/utils/sort_utils.c srcs/utils/validate_and_parse_utils.c\
	   srcs/validation/validate.c\
       srcs/operations/swap.c srcs/operations/push.c srcs/operations/rotate.c srcs/operations/rotate_reverse.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


