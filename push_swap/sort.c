/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:10:34 by leberton          #+#    #+#             */
/*   Updated: 2025/06/30 22:45:11 by leberton         ###   ########.fr       */
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

static int	find_position_of_lowest(t_list *list)
{
	int	lowest_value;
	int	lowest_pos;
	int	current_pos;

	lowest_value = INT_MAX;
	lowest_pos = 0;
	current_pos = 0;
	while (list)
	{
		if (list->index < lowest_value)
		{
			lowest_value = list->index;
			lowest_pos = current_pos;
		}
		list = list->next;
		current_pos++;
	}
	return (lowest_pos);
}

static void simple_sort(t_list **list_a, t_list **list_b)
{
	int lowest_pos;
	int size;

	while (*list_a)
	{
		size = ft_lstsize(*list_a);
		lowest_pos = find_position_of_lowest(*list_a);
		if (lowest_pos <= size / 2)
			while (lowest_pos-- > 0)
				rotate_a(list_a);
		else
		{
			lowest_pos = size - lowest_pos;
			while (lowest_pos-- > 0)
				rotate_reverse_a(list_a);
		}
		push_b(list_a, list_b);
	}
	while (*list_b)
		push_a(list_a, list_b);
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
	if (!is_sorted(list_a) && size <= 5)
		simple_sort(list_a, list_b);
	else if (!is_sorted(list_a))
		radinx_sort(list_a, list_b);
}
