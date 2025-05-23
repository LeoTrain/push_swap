/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:51:54 by leberton          #+#    #+#             */
/*   Updated: 2025/05/23 07:44:29 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *copy_list(t_list *src)
{
	t_list *copy = NULL;
	t_list *new_node;
	int    *value;

	while (src)
	{
		value = malloc(sizeof(int));
		if (!value)
			return (NULL);
		*value = *(int *)src->content;
		new_node = ft_lstnew(value);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&copy, new_node);
		src = src->next;
	}
	return copy;
}

static int sort_tabs(t_list **tab_a, t_list **tab_b)
{
	int steps = 0;
	int pos;
	int size;

	while (*tab_a)
	{
		pos = find_position_of_lowest(*tab_a);
		size = ft_lstsize(*tab_a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rotate(tab_a, 1);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rotate_reverse(tab_a, 1);
		}
		push(tab_a, tab_b, 1);
		steps++;
	}
	return steps;
}

int	main(int argc, char **argv)
{
	t_list	*tab_a = NULL;
	t_list	*tab_acopy = NULL;
	t_list	*tab_b = NULL;
	t_list	*tab_bcopy = NULL;
	int		i = 1;
	int		steps;

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
	tab_acopy = copy_list(tab_a);
	tab_bcopy = copy_list(tab_b);
	steps = sort_tabs(&tab_a, &tab_b);
	print_ints_array(tab_acopy, tab_bcopy);
	print_ints_array(tab_a, tab_b);
	printf("TOTAL STEPS: %d\n", steps);
	return (0);
}
