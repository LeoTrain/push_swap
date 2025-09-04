/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:10:28 by leberton          #+#    #+#             */
/*   Updated: 2025/09/04 15:11:17 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

static int	has_stack_duplicates(t_stack *stack);
static void	assign_indexes(t_stack *stack);
static void	init_data(int argc, char **argv, t_stack **stack_a,
				t_stack **stack_b);

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (EXIT_SUCCESS);
	stack_a = NULL;
	stack_b = NULL;
	init_data(argc, argv, &stack_a, &stack_b);
	size = stack_size(stack_a);
	if (size <= 5)
		sort_small(&stack_a, &stack_b, size);
	else
		optimized_sort(&stack_a, &stack_b);
	cleanup_and_exit(stack_a, stack_b, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static void	init_data(int argc, char **argv, t_stack **stack_a,
			t_stack **stack_b)
{
	if (validate_and_parse(argc, argv, stack_a) == EXIT_FAILURE)
	{
		write(2, "Error\n", 6);
		cleanup_and_exit(*stack_a, *stack_b, EXIT_FAILURE);
	}
	if (has_stack_duplicates(*stack_a) == EXIT_FAILURE)
	{
		write(2, "Error\n", 6);
		cleanup_and_exit(*stack_a, *stack_b, EXIT_FAILURE);
	}
	assign_indexes(*stack_a);
	if (is_sorted(*stack_a) == EXIT_SUCCESS)
		cleanup_and_exit(*stack_a, *stack_b, EXIT_SUCCESS);
}

static void	assign_indexes(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current)
	{
		current->index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}

static int	has_stack_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (compare->value == current->value)
				return (EXIT_FAILURE);
			compare = compare->next;
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}
