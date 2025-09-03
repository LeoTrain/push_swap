#include "../../includes/push_swap.h"

void	rra(t_stack	**stack_a)
{
	t_stack	*last;
	t_stack	*second_last;
	
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	second_last = NULL;
	last = *stack_a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack	**stack_b)
{
	t_stack	*last;
	t_stack	*second_last;
	
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	second_last = NULL;
	last = *stack_b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_a;
	t_stack	*second_last_a;
	t_stack	*last_b;
	t_stack *second_last_b;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		second_last_a = NULL;
		last_a = *stack_a;
		while (last_a->next)
		{
			second_last_a = last_a;
			last_a = last_a->next;
		}
		second_last_a->next = NULL;
		last_a->next = *stack_a;
		*stack_a = last_a;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		second_last_b = NULL;
		last_b = *stack_b;
		while (last_b->next)
		{
			second_last_b = last_b;
			last_b = last_b->next;
		}
		second_last_b->next = NULL;
		last_b->next = *stack_b;
		*stack_b = last_b;
	}
	write(1, "rrr\n", 4);
}
