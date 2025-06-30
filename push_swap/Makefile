CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = utils.c ft_utils.c ft_split.c list.c swap.c rotate.c rotate_reverse.c push.c sort.c arg_checker.c create_list_from_args.c main.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)
	cc $(FLAGS) -o $(NAME) $(OBJS)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
