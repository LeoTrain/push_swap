#include "../../includes/push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = get_last(*stack_a);
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = get_last(*stack_b);
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*last_a;
	t_stack	*first_b;
	t_stack	*last_b;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		first_a = *stack_a;
		last_a = get_last(*stack_a);
		*stack_a = first_a->next;
		first_a->next = NULL;
		last_a->next = first_a;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		first_b = *stack_b;
		last_b = get_last(*stack_b);
		*stack_b = first_b->next;
		first_b->next = NULL;
		last_b->next = first_b;
	}
	write(1, "rr\n", 3);
}
