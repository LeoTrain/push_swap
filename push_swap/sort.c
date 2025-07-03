/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:10:34 by leberton          #+#    #+#             */
/*   Updated: 2025/07/01 20:23:46 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_elements(t_list **list)
{
	int	first;
	int	second;
	int	third;

	first = (*list)->content;
	second = (*list)->next->content;
	third = (*list)->next->next->content;
	if (first > second && second < third && first < third)
		swap_a(list);
	else if (first > second && second > third)
	{
		swap_a(list);
		rotate_reverse_a(list);
	}
	else if (first > second && second < third && first > third)
		rotate_a(list);
	else if (first < second && second > third && first < third)
	{
		swap_a(list);
		rotate_a(list);
	}
	else if (first < second && second > third && first > third)
		rotate_reverse_a(list);
}

static void	insertion_sort(t_list **list_a, t_list **list_b)
{
	int	lowest_pos;
	int	size;

	while (*list_a)
	{
		size = ft_lstsize(*list_a);
		lowest_pos = lowest_index_position(*list_a);
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

static void	radix_sort(t_list **list_a, t_list **list_b)
{
	int	biggest;
	int	max_bits;
	int	i;
	int	j;
	int	size;

	i = 0;
	biggest = max_index(*list_a);
	max_bits = bit_length(biggest);
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
	if (size == 2 && !list_is_sorted(list_a))
		swap_a(list_a);
	else if (size == 3)
		sort_three_elements(list_a);
	else if (!list_is_sorted(list_a) && size <= 20)
		insertion_sort(list_a, list_b);
	else if (!list_is_sorted(list_a))
		radix_sort(list_a, list_b);
}
