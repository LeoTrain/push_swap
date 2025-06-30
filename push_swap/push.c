/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:54:31 by leberton          #+#    #+#             */
/*   Updated: 2025/06/30 22:14:51 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **from, t_list **to)
{
	t_list *list_ptr;

	if (from == NULL || *from == NULL)
		return ;
	list_ptr = *from;
	*from = (*from)->next;
	list_ptr->next = *to;
	*to = list_ptr;
}

void	push_a(t_list **list_a, t_list **list_b)
{
	push(list_b, list_a);
	write(1, "pa\n", 3);
}

void	push_b(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b);
	write(1, "pb\n", 3);
}
