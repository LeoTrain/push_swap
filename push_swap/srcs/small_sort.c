#include "../includes/push_swap.h"

static int	find_min_position(t_stack *stack)
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

static void	move_min_to_top(t_stack **stack_a, int size)
{
	int	min_pos;

	min_pos = find_min_position(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
}

static void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

static void	sort_three(t_stack	**stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	move_min_to_top(stack_a, 4);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	move_min_to_top(stack_a, 5);
	pb(stack_a, stack_b);
	move_min_to_top(stack_a, 4);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
