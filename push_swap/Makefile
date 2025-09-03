NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -g 
SRCS = srcs/args/args_validator_utils.c srcs/args/args_validator.c srcs/args/args_parser.c\
	srcs/ft_func/ft_utils.c srcs/ft_func/ft_split.c srcs/ft_func/list.c srcs/ft_func/list_cleanup.c\
	srcs/cmds/swap.c srcs/cmds/rotate.c srcs/cmds/rotate_reverse.c srcs/cmds/push.c\
	srcs/utils.c srcs/sort.c srcs/sort_utils.c srcs/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
