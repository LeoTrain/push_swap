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

static int	valide_and_parse_single(char *str, t_stack **stack_a);
static int	validate_and_parse_multiple(int argc, char **argv,
				t_stack **stack_a);

int	validate_and_parse(int argc, char **argv, t_stack **stack_a)
{
	if (argc == 2)
		return (valide_and_parse_single(*(argv + 1), stack_a));
	else
		return (validate_and_parse_multiple(argc, argv, stack_a));
	return (EXIT_FAILURE);
}

static int	valide_and_parse_single(char *str, t_stack **stack_a)
{
	char	**args;
	char	**args_p;
	int		count;

	args = ft_split(str, ' ');
	if (!args)
		return (EXIT_FAILURE);
	count = 0;
	args_p = args;
	while (args_p[count] != NULL)
		count++;
	if (validate_and_parse_multiple(count + 1, args - 1, stack_a))
	{
		while (count-- > 0)
			free(args[count]);
		free(args);
		return (EXIT_FAILURE);
	}
	while (count-- > 0)
		free(args[count]);
	free(args);
	return (EXIT_SUCCESS);
}

static int	validate_and_parse_multiple(int argc, char **argv,
		t_stack **stack_a)
{
	int		i;
	int		value;
	t_stack	*current_node;
	t_stack	*new_node;

	i = 1;
	current_node = NULL;
	*stack_a = NULL;
	while (i < argc)
	{
		if (check_validity(argv, i, &value, stack_a) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (create_new_node(&new_node, stack_a, value) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		fill_stack(stack_a, &new_node, &current_node);
		i++;
	}
	return (EXIT_SUCCESS);
}
