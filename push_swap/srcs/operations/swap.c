#include "../../includes/push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*second_a;
	t_stack	*first_b;
	t_stack	*second_b;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		first_a = *stack_a;
		second_a = (*stack_a)->next;
		first_a->next = second_a->next;
		second_a->next = first_a;
		*stack_a = second_a;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		first_b = *stack_b;
		second_b = (*stack_b)->next;
		first_b->next = second_b->next;
		second_b->next = first_b;
		*stack_b = second_b;
	}
	write(1, "ss\n", 3);
}
