/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:13:49 by leberton          #+#    #+#             */
/*   Updated: 2025/09/04 15:37:11 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b);
static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);
static void	rotate_to_max(t_stack **stack_b);
static void	add_to_chunk_end(int *chunk_end, int *pushed, int chunk_size);

void	optimized_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_chunks_to_b(stack_a, stack_b);
	push_back_to_a(stack_a, stack_b);
}

static void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk_size;
	int	pushed;
	int	chunk_end;

	size = stack_size(*stack_a);
	chunk_size = get_chunk_size(size);
	pushed = 0;
	chunk_end = chunk_size;
	while (*stack_a)
	{
		if ((*stack_a)->index < chunk_end)
		{
			pb(stack_a, stack_b);
			if (*stack_b && (*stack_b)->index < chunk_end - chunk_size / 2)
				rb(stack_b);
			pushed++;
			if (pushed == chunk_size)
				add_to_chunk_end(&chunk_end, &pushed, chunk_size);
		}
		else
			ra(stack_a);
	}
}

static void	add_to_chunk_end(int *chunk_end, int *pushed, int chunk_size)
{
	*chunk_end += chunk_size;
	*pushed = 0;
}

static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		rotate_to_max(stack_b);
		pa(stack_a, stack_b);
	}
}

static void	rotate_to_max(t_stack **stack_b)
{
	int	max_pos;
	int	size;

	max_pos = find_max_position(*stack_b);
	size = stack_size(*stack_b);
	if (max_pos <= size / 2)
	{
		while (max_pos > 0)
		{
			rb(stack_b);
			max_pos--;
		}
	}
	else
	{
		max_pos = size - max_pos;
		while (max_pos > 0)
		{
			rrb(stack_b);
			max_pos--;
		}
	}
}
