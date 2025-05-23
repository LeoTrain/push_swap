CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c is_includes.c swap.c rotate.c push.c utils.c push_swap.c rotate_reverse.c
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
