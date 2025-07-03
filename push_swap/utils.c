/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:56:58 by leberton          #+#    #+#             */
/*   Updated: 2025/07/01 20:23:27 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_with_error(char *str, int error)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
	exit(error);
}

int	bit_length(int biggest_nbr)
{
	int	max_bits;

	max_bits = 0;
	while (biggest_nbr > 0)
	{
		biggest_nbr >>= 1;
		max_bits++;
	}
	return (max_bits);
}

int	list_is_sorted(t_list **list)
{
	t_list	*temp;

	temp = *list;
	while (temp && temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	lowest_index_position(t_list *list)
{
	int	lowest_value;
	int	lowest_pos;
	int	current_pos;

	lowest_value = INT_MAX;
	lowest_pos = 0;
	current_pos = 0;
	while (list)
	{
		if (list->index < lowest_value)
		{
			lowest_value = list->index;
			lowest_pos = current_pos;
		}
		list = list->next;
		current_pos++;
	}
	return (lowest_pos);
}


int	max_index(t_list *list)
{
	int		big;
	t_list	*temp;

	big = INT_MIN;
	temp = list;
	while (temp)
	{
		if (temp->index > big)
			big = temp->index;
		temp = temp->next;
	}
	return (big);
}
