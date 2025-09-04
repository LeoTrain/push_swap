#include "../../includes/push_swap.h"
#include <stdlib.h>

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (EXIT_SUCCESS);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (EXIT_FAILURE);
		stack = stack->next;
	}
	return (EXIT_SUCCESS);
}
