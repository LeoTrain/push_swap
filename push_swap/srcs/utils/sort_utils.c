/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:14:51 by leberton          #+#    #+#             */
/*   Updated: 2025/09/04 15:19:57 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	if (size <= 500)
		return (45);
	return (size / 11);
}

int	find_max_position(t_stack *stack)
{
	t_stack	*current;
	int		max_index;
	int		max_pos;
	int		pos;

	current = stack;
	max_index = stack->index;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

int	find_min_position(t_stack *stack)
{
	int	min_index;
	int	min_pos;
	int	current_pos;

	min_index = stack->index;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack **stack_a, int size)
{
	int	min_pos;
	int	steps;

	min_pos = find_min_position(*stack_a);
	if (min_pos <= size / 2)
	{
		steps = min_pos;
		while (steps-- > 0)
			ra(stack_a);
	}
	else
	{
		steps = size - min_pos;
		while (steps-- > 0)
			rra(stack_a);
	}
}
