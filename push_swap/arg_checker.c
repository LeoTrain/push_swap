/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:25:38 by leberton          #+#    #+#             */
/*   Updated: 2025/06/30 21:05:29 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	doubles_checker(char **argv, int length)
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

static int	number_checker(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	get_array_length(char **array)
{
	int	length;

	length = 0;
	while (array[length])
		length++;
	return (length);
}

void	assign_indexes(t_list *head, int link_size)
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

void	argv_checker(int argc, char **argv)
{
	int		i;
	long	temp_arg;
	int		length;
	char	**temp;

	i = 0;
	if (argc == 2)
		temp = ft_split(argv[1], ' ');
	else
		temp = argv + 1;
	while (temp[i])
	{
		temp_arg = ft_atoi(temp[i]);
		if (temp_arg < INT_MIN || temp_arg > INT_MAX)
			ft_puterror("ERROR");
		if (number_checker(temp[i]))
			ft_puterror("ERROR");
		i++;
	}
	length = get_array_length(temp);
	if (doubles_checker(temp, length))
		ft_puterror("ERROR");
	if (argc == 2)
		ft_free_split(temp);
}
