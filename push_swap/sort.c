/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:10:34 by leberton          #+#    #+#             */
/*   Updated: 2025/06/30 20:28:59 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_bits(int biggest_nbr)
{
	int	max_bits;

	max_bits = 0;
	while (biggest_nbr > 0)
	{
		biggest_nbr >>= 1;
		max_bits++;
	}
	return (max_bits);
}

static void simple_sort(t_list **list)
{
	int	biggest;

	biggest = find_biggest(*list);
	if ((*list)->index == biggest)
		rotate_a(list);
	else if ((*list)->next->index == biggest)
		rotate_reverse_a(list);
	if ((*list)->index > (*list)->next->index)
		swap_a(list);
}

static void small_sort(t_list **list_a, t_list **list_b)
{
	int size;

	size = ft_lstsize(*list_a);
	while (size > 3)
	{
		if ((*list_a)->index == 0 || (*list_a)->index == 1)
			push_b(list_a, list_b);
		else
			rotate_a(list_a);
		size--;
	}
	simple_sort(list_a);
	push_a(list_a, list_b);
	push_a(list_a, list_b);
	if ((*list_a)->index > (*list_b)->next->index)
		swap_a(list_a);
}

static void	radinx_sort(t_list **list_a, t_list **list_b)
{
	int	biggest;
	int	max_bits;
	int	i;
	int	j;
	int	size;

	i = 0;
	biggest = find_biggest(*list_a);
	max_bits = find_bits(biggest);
	size = ft_lstsize(*list_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*list_a)->index >> i) & 1)
				rotate_a(list_a);
			else
				push_b(list_a, list_b);
			j++;
		}
		while (*list_b)
			push_a(list_a, list_b);
		i++;
	}
}

void	sort_list(t_list **list_a, t_list **list_b)
{
	int	size;

	size = ft_lstsize(*list_a);
	if (!is_sorted(list_a) && size <= 3)
		simple_sort(list_a);
	else if (!is_sorted(list_a) && size <= 5)
		small_sort(list_a, list_b);
	else if (!is_sorted(list_a))
		radinx_sort(list_a, list_b);
}
