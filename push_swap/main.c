/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:55:05 by leberton          #+#    #+#             */
/*   Updated: 2025/06/30 23:15:00 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		printf("val: %d | index: %d\n", tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		return (0);
	argv_checker(argc, argv);
	list_a = create_list_from_args(argc, argv);
	list_b = NULL;
	assign_indexes(list_a, ft_lstsize(list_a));
	// print_list(&list_a);
	sort_list(&list_a, &list_b);
	// print_list(&list_a);
	return (0);
}
