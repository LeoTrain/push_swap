/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:51:54 by leberton          #+#    #+#             */
/*   Updated: 2025/05/22 17:42:20 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*tab_a = NULL;
	t_list	*tab_b = NULL;
	int		i = 1;
	int		lowest;

	if (argc < 2)
		return (0);
	while (i < argc)
	{
		int *value = malloc(sizeof(int));
		if (!value)
			return (ft_puterror());
		*value = atoi(argv[i++]);
		ft_lstadd_back(&tab_a, ft_lstnew(value));
	}
	print_ints_array(tab_a, tab_b);
	lowest = check_for_lowest(tab_a);
	int steps = 0;
	while (tab_a)
	{
		// case 1: a is_lowest of a and b is lowest of b, a is greater than b
		// case 2: a is lowest of a and b is lowest of b, a is less than b
		// case 3: a is lowest of a and b is lowest of b, a is equal to b
		// case 4: a is lowest of a and b is not lowest of b, a is greater than b
		// case 5: a is lowest of a and b is not lowest of b, a is less than b
		// case 6: a is lowest of a and b is not lowest of b, a is equal to b
		//
		// case 7: a is not lowest of a and b is lowest of b, a is greater than b
		// case 8: a is not lowest of a and b is lowest of b, a is less than b
		// case 9: a is not lowest of a and b is lowest of b, a is equal to b
		// case 10: a is not lowest of a and b is not lowest of b, a is greater than b
		// case 11: a is not lowest of a and b is not lowest of b, a is less than b
		// case 12: a is not lowest of a and b is not lowest of b, a is equal to b
		//
		// Handling:
		if (*(int *)tab_a->content == lowest || (tab_b && *(int *)tab_a->content == *(int *)tab_b->content))
		{
			push(&tab_a, &tab_b, 1);
			lowest = check_for_lowest(tab_a);
		}
		else
			rotate(&tab_a, 1);
		steps++;
	}
	print_ints_array(tab_a, tab_b);
	printf("TOTAL STEPS: %d\n", steps);
	return (0);
}
