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
	if (is_a)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

