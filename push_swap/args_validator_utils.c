/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 00:54:26 by leberton          #+#    #+#             */
/*   Updated: 2025/07/04 00:55:11 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_length(char **array)
{
	int	length;

	length = 0;
	while (array[length])
		length++;
	return (length);
}

void	error_if_empty_args(int argc, char **argv)
{
	char	*str;

	str = argv[1];
	if (argc < 2)
		exit(0);
	else if (argc >= 2)
	{
		if (!str || *str == '\0')
			exit_with_error("Error", 1);
		while (*str)
		{
			if (*str != ' ' && (*str < 9 || *str > 13))
				return ;
			str++;
		}
		exit_with_error("Error", 1);
	}
}

int	has_duplicates(char **argv, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = 1 + i;
		while (j < length)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_number(char *arg)
{
	int			i;
	long long	temp_arg;

	i = 0;
	temp_arg = ft_atoll(arg);
	if (temp_arg < INT_MIN || temp_arg > INT_MAX)
		return (1);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

void	assign_list_indexes(t_list *head, int link_size)
{
	t_list	*biggest;
	t_list	*temp;

	while (link_size-- > 0)
	{
		biggest = NULL;
		temp = head;
		while (temp)
		{
			if (!temp->index && (biggest == NULL
					|| temp->content > biggest->content))
				biggest = temp;
			temp = temp->next;
		}
		if (biggest)
			biggest->index = link_size;
	}
}
