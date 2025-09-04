#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
} t_stack;

int	stack_size(t_stack *stack);
t_stack	*get_last(t_stack *stack);
int	is_sorted(t_stack *stack);

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size);
void	optimized_sort(t_stack **stack_a, t_stack **stack_b);

void	free_stack(t_stack *stack);
void	cleanup_and_exit(t_stack *stack_a, t_stack *stack_b, int exit_code);

// Swap operations
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);

// Push operations  
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);

// Rotate operations
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);

// Rotate reverse operations
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);
#endif
