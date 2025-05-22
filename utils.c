/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:56:58 by leberton          #+#    #+#             */
/*   Updated: 2025/05/22 16:58:57 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_lowest(t_list *tab)
{
	if (!tab)
		return (INT_MAX);
	int lowest = *(int *)tab->content;
	while (tab)
	{
		if (*(int *)tab->content < lowest)
			lowest = *(int *)tab->content;
		tab = tab->next;
	}
	return (lowest);
}

int	ft_puterror(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	print_ints_array(t_list *tab_a, t_list *tab_b)
{
	while (tab_a || tab_b)
	{
		if (tab_a)
		{
			printf("%-3d", *(int *)tab_a->content);
			tab_a = tab_a->next;
		}
		else
			printf("   ");
		printf("   ");
		if (tab_b)
		{
			printf("%-3d", *(int *)tab_b->content);
			tab_b = tab_b->next;
		}
		printf("\n");
	}
	printf("---   ---\n");
	printf(" a     b\n");
}
