/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:25:38 by leberton          #+#    #+#             */
/*   Updated: 2025/07/04 00:50:58 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	generate_temp_arguments(int argc, char **argv, char ***temp)
{
	if (argc == 2)
	{
		*temp = ft_split(argv[1], ' ');
		if (!temp || !temp[0])
			exit_with_error("Error", 1);
	}
	else
		*temp = argv + 1;
}

void	validate_args(int argc, char **argv)
{
	int		i;
	long	temp_arg;
	int		length;
	char	**temp;

	i = 0;
	error_if_empty_args(argc, argv);
	if (argc == 2)
		generate_temp_arguments(argc, argv, &temp);
	else
		temp = argv + 1;
	while (temp[i])
	{
		temp_arg = ft_atoi(temp[i]);
		if (temp_arg < INT_MIN || temp_arg > INT_MAX)
			exit_with_error("Error", 1);
		if (is_valid_number(temp[i]))
			exit_with_error("Error", 2);
		i++;
	}
	length = array_length(temp);
	if (has_duplicates(temp, length))
		exit_with_error("Error", 3);
	if (argc == 2)
		ft_free_split(temp);
}
