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

void	swap(t_list **list)
{
	t_list *first;
	t_list *second;

	if (!*list || !(*list)->next)
		return ;
	first = *list;
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void	swap_a(t_list **list)
{
	swap(list);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **list)
{
	swap(list);
	write(1, "sb\n", 3);
}

void	swap_ab(t_list **tab_a, t_list **tab_b)
{
	swap(tab_a);
	swap(tab_b);
	write(1, "ss\n", 3);
}
