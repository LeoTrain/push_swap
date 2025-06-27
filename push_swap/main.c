/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:55:05 by leberton          #+#    #+#             */
/*   Updated: 2025/05/23 08:56:02 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*tab_a = NULL;
	t_list	*tab_b = NULL;

	if (argc < 2)
		return (1);
	if (!argv_checker(argc, argv))
		return (ft_puterror(1));
	tab_a = create_tab_from_args(argv+1);
	if (tab_a == NULL)
		return (ft_puterror(3));
	push_swap(&tab_a, &tab_b);
	return (0);
}
