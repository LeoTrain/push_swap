/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:52:49 by leberton          #+#    #+#             */
/*   Updated: 2025/05/22 16:56:21 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **tab, int is_a)
{
	t_list *first;
	t_list *second;
	if (!*tab || !(*tab)->next)
		return ;
	first = *tab;
	second = (*tab)->next;
	first->next = second->next;
	second->next = first;
	*tab = second;
	if (is_a == 1)
		write(1, "sa\n", 3);
	else if (is_a == 0)
		write(1, "sb\n", 3);
}

void	swap_ab(t_list **tab_a, t_list **tab_b)
{
	swap(tab_a, -1);
	swap(tab_b, -1);
	write(1, "ss\n", 3);
}
