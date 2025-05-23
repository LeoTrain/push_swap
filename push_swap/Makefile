CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_isdigit.c ft_atoi.c ft_atoll.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c swap.c rotate.c push.c utils.c push_swap.c rotate_reverse.c arg_checker.c  main.c create_tab_from_args.c
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
