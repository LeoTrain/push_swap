/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:55:05 by leberton          #+#    #+#             */
/*   Updated: 2025/07/01 18:57:44 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		return (0);
	validate_args(argc, argv);
	list_a = create_list_from_args(argc, argv);
	list_b = NULL;
	assign_list_indexes(list_a, ft_lstsize(list_a));
	sort_list(&list_a, &list_b);
	ft_lstclear(&list_a, free);
	ft_lstclear(&list_b, free);
	return (0);
}
