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

static int	find_min_index(t_list *list)
{
	int		i = 0;
	int		min_index = -1;
	int		min_value = INT_MAX;
	t_list	*current = list;

	while (current)
	{
		if ((int)current->content < min_value)
		{
			min_value = (int)current->content;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

static void	push_min_to_b(t_list **list_a, t_list **list_b)
{
	int		min_index;
	int		size;
	
	min_index = find_min_index(*list_a);
	size = ft_lstsize(*list_a);
	if (min_index <= size / 2)
		while (min_index-- > 0)
			rotate_a(list_a);
	else
		while (min_index++ < size)
			rotate_reverse_a(list_a);
	push_b(list_a, list_b);
}

void	sort_five_elements(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 5)
		push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three_elements(a);
	push_a(a, b);
	if ((*a)->content > (*a)->next->content)
		swap_a(a);
	push_a(a, b);
	if ((*a)->content > (*a)->next->content)
		swap_a(a);
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
	else if (!list_is_sorted(list_a) && size <= 5)
		sort_five_elements(list_a, list_b);
	else if (!list_is_sorted(list_a))
		radix_sort(list_a, list_b);
}
