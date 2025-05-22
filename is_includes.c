/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_includes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:50:14 by leberton          #+#    #+#             */
/*   Updated: 2025/05/22 16:50:44 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *tab)
{
	while (tab && tab->next)
	{
		if (*(int *)tab->content > *(int *)tab->next->content)
			return (0);
		tab = tab->next;
	}
	return (1);
}

int	is_lower(t_list *tab, int value)
{
	if (*(int *)tab->content < value)
		return (1);
	return (0);
}
