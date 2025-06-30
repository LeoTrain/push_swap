/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_from_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:53:51 by leberton          #+#    #+#             */
/*   Updated: 2025/06/30 21:04:46 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_free_list(t_list *list, char **temp, int argc)	
{
	ft_lstclear(&list, free);
	if (argc == 2)
		ft_free_split(temp);
}

static int add_arg_to_list(t_list **list_a, char **temp, int i, int argc)
{
	t_list	*new;

	new = ft_lstnew(ft_atoi(temp[i]));
	if (!new)
	{
		ft_free_list(*list_a, temp, argc);
		return (0);
	}
	ft_lstadd_back(list_a, new);
	return (1);
}

t_list *create_list_from_args(int argc, char **argv)
{
	int		i;
	t_list	*list_a;
	char	**temp;

	i = 0;
	list_a = NULL;
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		if (!temp || !temp[0])
			return (NULL);
	}
	else
	{
		i = 1;
		temp = argv;
	}
	while (temp[i])
	{
		if (!add_arg_to_list(&list_a, temp, i, argc))
			return (NULL);
		i++;
	}
	if (argc == 2)
		ft_free_split(temp);
	return(list_a);
}
