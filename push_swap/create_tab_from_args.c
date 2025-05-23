/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_from_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:53:51 by leberton          #+#    #+#             */
/*   Updated: 2025/05/23 08:54:23 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *create_tab_from_args(char **argv)
{
	t_list	*tab_a;
	int		i;

	tab_a= NULL;
	i = 0;
	while (argv[i])
	{
		int *value = malloc(sizeof(int));
		if (!value)
			return (NULL);
		*value = ft_atoi(argv[i]);
		ft_lstadd_back(&tab_a, ft_lstnew(value));
		i++;
	}
	return (tab_a);
}

