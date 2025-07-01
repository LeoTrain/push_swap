/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:58:20 by leberton          #+#    #+#             */
/*   Updated: 2025/07/01 18:58:38 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

char		**ft_split(const char *s, char c);
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *nptr);
void		ft_lstadd_back(t_list **lst, t_list *new_list);
void		ft_lstadd_front(t_list **lst, t_list *new_list);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst, void (*del)(void *));
int			ft_puterror(char *str);
void		ft_free_split(char **split);

void		swap_a(t_list **list);
void		swap_b(t_list **list);
void		swap_ab(t_list **tab_a, t_list **tab_b);
void		rotate_a(t_list **list);
void		rotate_b(t_list **list);
void		rotate_ab(t_list **list_a, t_list **list_b);
void		rotate_reverse_a(t_list **list);
void		rotate_reverse_b(t_list **list);
void		rotate_reverse_ab(t_list **list_a, t_list **list_b);
void		push_a(t_list **list_a, t_list **list_b);
void		push_b(t_list **list_a, t_list **list_b);

void		assign_indexes(t_list *head, int link_size);
int			find_biggest(t_list *list);
int			is_sorted(t_list **list);
void		sort_list(t_list **list_a, t_list **list_b);
void		argv_checker(int argc, char **argv);
t_list		*create_list_from_args(int argc, char **argv);

#endif 
