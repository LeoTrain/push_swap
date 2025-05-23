/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:51:54 by leberton          #+#    #+#             */
/*   Updated: 2025/05/23 08:56:17 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_swap(t_list **tab_a, t_list **tab_b)
{
	int steps;
	int pos;
	int size;

	steps = 0;
	while (*tab_a)
	{
		pos = find_position_of_lowest(*tab_a);
		size = ft_lstsize(*tab_a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rotate(tab_a, 1);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rotate_reverse(tab_a, 1);
		}
		push(tab_a, tab_b, 0);
		steps++;
	}
	return steps;
}
