/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:25:38 by leberton          #+#    #+#             */
/*   Updated: 2025/06/30 20:14:47 by leberton         ###   ########.fr       */
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

static int number_checker(char *arg)
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

void	assign_indexes(t_list *head, int link_size)
{
	t_list	*biggest;
	t_list	*tmp;

	while (link_size-- > 0)
	{
		biggest = NULL;
		tmp = head;
		while (tmp)
		{
			if (!tmp->index && (biggest == NULL || *(int *)tmp->content > *(int *)biggest->content))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest)
			biggest->index = link_size;
	}
}

void	argv_checker(int argc, char **argv)
{
	int		i;
	long	j;
	int		length;
	char	**args;

	i = 0;
	length = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	while (args[i])
	{
		j = ft_atoi(args[i]);
		if (j < INT_MIN || j > INT_MAX)
			ft_puterror("ERROR");
		if (number_checker(args[i]))
			ft_puterror("ERROR");
		i++;
	}
	while (args[length])
		length++;
	if (doubles_checker(args, length))
		ft_puterror("ERROR");
	if (argc == 2)
		ft_free_split(args);
}
