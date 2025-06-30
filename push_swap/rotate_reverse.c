/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:13:04 by leberton          #+#    #+#             */
/*   Updated: 2025/06/30 23:14:16 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse(t_list **list)
{
	t_list	*last;
	t_list	*before_last;

	if (!*list || !(*list)->next)
		return ;
	last = ft_lstlast(*list);
	before_last = *list;
	while (before_last->next->next)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *list;
	*list = last;
}

void	rotate_reverse_a(t_list **list)
{
	rotate_reverse(list);
	write(1, "rra\n", 4);
}

void	rotate_reverse_b(t_list **list)
{
	rotate_reverse(list);
	write(1, "rrb\n", 4);
}

void	rotate_reverse_ab(t_list **list_a, t_list **list_b)
{
	rotate_reverse(list_a);
	rotate_reverse(list_b);
	write(1, "rrr\n", 4);
}
