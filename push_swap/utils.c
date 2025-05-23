/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:56:58 by leberton          #+#    #+#             */
/*   Updated: 2025/05/23 08:39:09 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_puterror(int error)
{
	write(2, "Error\n", 6);
	return (error);
}

int find_position_of_lowest(t_list *lst)
{
	int min = *(int *)lst->content;
	int pos = 0;
	int i = 0;
	t_list *tmp = lst;

	while (tmp)
	{
		if (*(int *)tmp->content < min)
		{
			min = *(int *)tmp->content;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return pos;
}
