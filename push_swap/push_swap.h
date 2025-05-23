#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
long long ft_atoll(const char *nptr);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void	*content);
int		ft_lstsize(t_list *lst);

int		ft_puterror(int error);
void	swap(t_list **tab, int is_a);
void	swap_ab(t_list **tab_a, t_list **tab_b);
void	rotate(t_list **tab, int is_a);
void	rotate_ab(t_list **tab_a, t_list **tab_b);
void	rotate_reverse(t_list **tab, int is_a);
void	rotate_reverse_ab(t_list **tab_a, t_list **tab_b);
void	push(t_list **tab_a, t_list **tab_b, int is_a);

int		find_position_of_lowest(t_list *lst);
int		argv_checker(int argc, char **argv);
t_list *create_tab_from_args(char **argv);
int		push_swap(t_list **tab_a, t_list **tab_b);

#endif 
