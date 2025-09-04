/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_parse_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:32:03 by leberton          #+#    #+#             */
/*   Updated: 2025/09/04 15:37:57 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_valid_integer(char *str, int *result);

int	check_validity(char **argv, int i, int *value, t_stack **stack_a)
{
	if (is_valid_integer(argv[i], value) == EXIT_FAILURE)
	{
		free_stack(*stack_a);
		*stack_a = NULL;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	create_new_node(t_stack **new_node, t_stack **stack_a, int value)
{
	*new_node = create_stack();
	if (!new_node)
	{
		free_stack(*stack_a);
		*stack_a = NULL;
		return (EXIT_FAILURE);
	}
	(*new_node)->value = value;
	return (EXIT_SUCCESS);
}

int	fill_stack(t_stack **stack_a, t_stack **new_node, t_stack **current_node)
{
	if (*stack_a == NULL)
	{
		*stack_a = *new_node;
		*current_node = *new_node;
	}
	else
	{
		(*current_node)->next = *new_node;
		*current_node = *new_node;
	}
	return (EXIT_SUCCESS);
}

static int	is_valid_integer(char *str, int *result)
{
	char	*original;
	long	temp;

	original = str;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (EXIT_FAILURE);
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (EXIT_FAILURE);
	temp = ft_atol(original);
	if (temp < INT_MIN || temp > INT_MAX)
		return (EXIT_FAILURE);
	*result = (int)temp;
	return (EXIT_SUCCESS);
}
