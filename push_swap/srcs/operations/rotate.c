#include "../../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/* do_ra:
*	Sends the top element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

/* do_rb:
*	Sends the top element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

/* do_rr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rr" to the standard output.
*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
