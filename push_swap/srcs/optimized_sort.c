#include "../includes/push_swap.h"

static void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b);
static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);
static void	smart_rotate_b(t_stack **stack_b, int position, int size);

void	optimized_sort(t_stack **stack_a, t_stack **stack_b)
{
    push_chunks_to_b(stack_a, stack_b);
    push_back_to_a(stack_a, stack_b);
}

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	else if (size <= 500)
		return (45);
	else
		return (size / 11);
}

static void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b)
{
    int	size;
    int	chunk_size;
    int	pushed;
    int	chunk_max;

    size = stack_size(*stack_a);
    chunk_size = get_chunk_size(size);
    pushed = 0;
    chunk_max = chunk_size;
    while (*stack_a)
    {
        if (pushed >= size)
            break;
        if ((*stack_a)->index >= size - chunk_max)
        {
            pb(stack_a, stack_b);
            if (*stack_b && (*stack_b)->index >= size - (chunk_max - chunk_size / 2))
                rb(stack_b);
            pushed = 0;
            if (stack_size(*stack_b) >= chunk_max)
                chunk_max += chunk_size;
        }
        else
        {
            ra(stack_a);
            pushed++;
        }
    }
}

static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int		min_index;
    int		min_pos;
    int		size;
    int		position;
    t_stack *current;

    while (*stack_b)
    {
        size = stack_size(*stack_b);
        min_index = 2147483647;
        min_pos = 0;
        current = *stack_b;
        position = 0;
        while (current)
        {
            if (current->index < min_index)
            {
                min_index = current->index;
                min_pos = position;
            }
            current = current->next;
            position++;
        }
        smart_rotate_b(stack_b, min_pos, size);
        pa(stack_a, stack_b);
    }
}

static void	smart_rotate_b(t_stack **stack_b, int position, int size)
{
	if (position == 0)
		return;
	if (position <= size / 2)
	{
		while (position-- > 0)
			rb(stack_b);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rrb(stack_b);
	}
}
