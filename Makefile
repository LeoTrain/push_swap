CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c is_includes.c swap.c rotate.c push.c utils.c push_swap.c
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

test: all
	@echo "Running tests with args: 1 4 2 5 -25 10"
	@./$(NAME) 1 4 2 5 -25 10 > test_output.txt
	@echo "Running tests with args: 10 0 24 -36 1 105 99 23 -35"
	@./$(NAME) 10 0 24 -36 1 105 99 23 -35 >> test_output.txt
	@echo "Running tests with args: 0 0 0 0 0 0 0 0 0 0"
	@./$(NAME) 0 0 0 0 0 0 0 0 0 0 >> test_output.txt
	@echo "Running tests with args: 10 20 10 20 35 10 35 20"
	@./$(NAME) 10 20 10 20 35 10 35 20 >> test_output.txt
	@echo "Running tests with args: 1 1 2 4 4 34 3255 453 2343 34 54523 4234 35 56 343432 4 35 56543 32 93939 93 430349 394 3 0 94 39 3 95 95049 394 309 90 34033 1 2 3 4 1 2 3 4 1 2 3 4 12 3 4 1 2 3 4 5 6 7 1 2 3 4 5 6 1 2 3 4 5 6"
	@./$(NAME) 1 1 2 4 4 34 3255 453 2343 34 54523 4234 35 56 343432 4 35 56543 32 93939 93 430349 394 3 0 94 39 3 95 95049 394 309 90 34033 1 2 3 4 1 2 3 4 1 2 3 4 12 3 4 1 2 3 4 5 6 7 1 2 3 4 5 6 1 2 3 4 5 6 >> test_output.txt
	@cat test_output.txt
