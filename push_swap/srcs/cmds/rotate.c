/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:53:28 by leberton          #+#    #+#             */
/*   Updated: 2025/07/01 18:58:57 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_list **tab)
{
	t_list	*first;
	t_list	*last;

	if (!*tab || !(*tab)->next)
		return ;
	first = *tab;
	last = ft_lstlast(*tab);
	*tab = (*tab)->next;
	first->next = NULL;
	last->next = first;
}

void	rotate_a(t_list **tab)
{
	rotate(tab);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **tab)
{
	rotate(tab);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_list **tab_a, t_list **tab_b)
{
	rotate(tab_a);
	rotate(tab_b);
	write(1, "rr\n", 3);
}
