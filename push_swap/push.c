/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:54:31 by leberton          #+#    #+#             */
/*   Updated: 2025/05/22 16:54:58 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **tab_a, t_list **tab_b, int is_a)
{
	t_list *node;

	if (!*tab_a)
		return ;
	node = *tab_a;
	*tab_a = (*tab_a)->next;
	node->next = NULL;
	ft_lstadd_front(tab_b, node);
	if (is_a)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
