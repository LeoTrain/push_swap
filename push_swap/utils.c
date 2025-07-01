/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:56:58 by leberton          #+#    #+#             */
/*   Updated: 2025/07/01 19:02:09 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_puterror(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
	exit(1);
}

int	find_position_of_lowest(t_list *lst)
{
	int		min;
	int		pos;
	int		i;
	t_list	*tmp;

	pos = 0;
	i = 0;
	tmp = lst;
	min = lst->content;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	is_sorted(t_list **list)
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

int	find_biggest(t_list *list)
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

int	find_bits(int biggest_nbr)
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
