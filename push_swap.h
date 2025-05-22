#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void	*content);
int		ft_lstsize(t_list *lst);
int		is_sorted(t_list *tab);
int		is_lower(t_list *tab, int value);
void	swap(t_list **tab, int is_a);
void	rotate(t_list **tab, int is_a);
void	push(t_list **tab_a, t_list **tab_b, int is_a);
int		check_for_lowest(t_list *tab);
int		ft_puterror(void);
void	print_ints_array(t_list *tab_a, t_list *tab_b);

#endif 
