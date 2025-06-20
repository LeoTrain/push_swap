/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:53:28 by leberton          #+#    #+#             */
/*   Updated: 2025/05/22 16:55:19 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **tab, int is_a)
{
	t_list *first;
	t_list *last;

	if (!*tab || !(*tab)->next)
		return ;
	first = *tab;
	last = ft_lstlast(*tab);
	*tab = (*tab)->next;
	first->next = NULL;
	last->next = first;
	if (is_a == 1)
		write(1, "ra\n", 3);
	else if (is_a == 0)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_list **tab_a, t_list **tab_b)
{
	rotate(tab_a, -1);
	rotate(tab_b, -1);
	write(1, "rr\n", 3);
}
