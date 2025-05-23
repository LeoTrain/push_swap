/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 07:13:04 by leberton          #+#    #+#             */
/*   Updated: 2025/05/23 07:13:45 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse(t_list **tab, int is_a)
{
	t_list	*last;
	t_list	*before_last;
	if (!*tab || !(*tab)->next)
		return ;
	last = ft_lstlast(*tab);
	before_last = *tab;
	while (before_last->next->next)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *tab;
	*tab = last;
	if (is_a == 1)
		write(1, "rra\n", 4);
	else if (is_a == 0)
		write(1, "rrb\n", 4);
}

void	rotate_reverse_ab(t_list **tab_a, t_list **tab_b)
{
	rotate_reverse(tab_a, -1);
	rotate_reverse(tab_b, -1);
	write(1, "rrr\n", 4);
}
