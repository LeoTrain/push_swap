/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:20:03 by leberton          #+#    #+#             */
/*   Updated: 2025/09/04 15:36:02 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	process_argument(char *arg, t_stack **stack_a);
static int	process_string_with_spaces(char *str, t_stack **stack_a);
static int	process_split_args(char **args, int count, t_stack **stack_a);
static int	add_single_number(char *str, t_stack **stack_a);

int	validate_and_parse(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	*stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (process_argument(argv[i], stack_a) == EXIT_FAILURE)
		{
			free_stack(*stack_a);
			*stack_a = NULL;
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	process_argument(char *arg, t_stack **stack_a)
{
	if (ft_strchr(arg, ' '))
		return (process_string_with_spaces(arg, stack_a));
	else
		return (add_single_number(arg, stack_a));
}

static int	process_string_with_spaces(char *str, t_stack **stack_a)
{
	char	**args;
	int		count;

	if (*str == '\0')
		return (EXIT_FAILURE);
	args = ft_split(str, ' ');
	if (!args)
		return (EXIT_FAILURE);
	count = 0;
	while (args[count] != NULL)
		count++;
	if (count == 0)
	{
		free(args);
		return (EXIT_FAILURE);
	}
	return (process_split_args(args, count, stack_a));
}

static int	process_split_args(char **args, int count, t_stack **stack_a)
{
	int	i;
	int	result;

	result = EXIT_SUCCESS;
	i = 0;
	while (i < count && result == EXIT_SUCCESS)
	{
		result = add_single_number(args[i], stack_a);
		i++;
	}
	i = 0;
	while (i < count)
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (result);
}

static int	add_single_number(char *str, t_stack **stack_a)
{
	int		value;
	t_stack	*new_node;
	t_stack	*current;

	if (is_valid_integer(str, &value) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	new_node = create_stack();
	if (!new_node)
		return (EXIT_FAILURE);
	new_node->value = value;
	new_node->next = NULL;
	if (*stack_a == NULL)
		*stack_a = new_node;
	else
	{
		current = *stack_a;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	return (EXIT_SUCCESS);
}
