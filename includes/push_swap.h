/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:41:11 by leberton          #+#    #+#             */
/*   Updated: 2025/09/04 15:41:15 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

int		ft_isspace(char c);
long	ft_atol(const char *str);

t_stack	*create_stack(void);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);

int		check_validity(char **argv, int i, int *value, t_stack **stack_a);
int		create_new_node(t_stack **new_node, t_stack **stack_a, int value);
int		fill_stack(t_stack **stack_a, t_stack **new_node,
			t_stack **current_node);
int		validate_and_parse(int argc, char **argv, t_stack **stack_a);

int		find_min_position(t_stack *stack);
int		find_max_position(t_stack *stack);
void	move_min_to_top(t_stack **stack_a, int size);
int		get_chunk_size(int size);

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size);
void	optimized_sort(t_stack **stack_a, t_stack **stack_b);

void	free_stack(t_stack *stack);
void	cleanup_and_exit(t_stack *stack_a, t_stack *stack_b, int exit_code);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
