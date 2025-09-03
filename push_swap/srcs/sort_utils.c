/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:43:55 by leberton          #+#    #+#             */
/*   Updated: 2025/07/09 11:45:25 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min_index(t_list *list)
{
	int		i;
	int		min_index;
	int		min_value;
	t_list	*current;

	i = 0;
	min_index = -1;
	min_value = INT_MAX;
	current = list;
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

void	push_min_to_b(t_list **list_a, t_list **list_b)
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
