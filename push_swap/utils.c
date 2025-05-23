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

int check_for_highest(t_list *tab)
{
	if (!tab)
		return (INT_MIN);
	int highest = *(int *)tab->content;
	while (tab)
	{
		if (*(int *)tab->content > highest)
			highest = *(int *)tab->content;
		tab = tab->next;
	}
	return (highest);
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

int	ft_puterror(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void print_centered(const char *str, int width)
{
    int len = (int)strlen(str);
    int padding = (width - len) / 2;
    int padding_right = width - len - padding;

    for (int i = 0; i < padding; i++)
        putchar(' ');
    printf("%s", str);
    for (int i = 0; i < padding_right; i++)
        putchar(' ');
}

void print_int_centered(int val, int width)
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", val);
    print_centered(buf, width);
}

void print_ints_array(t_list *tab_a, t_list *tab_b)
{
    int index = 0;

    print_centered("Index", 8);
    printf(" | ");
    print_centered("Stack A", 16);
    printf(" | ");
    print_centered("Stack B", 16);
    printf("\n");
    for (int i = 0; i < 8; i++) putchar('-');
    printf("-+-");
    for (int i = 0; i < 16; i++) putchar('-');
    printf("-+-");
    for (int i = 0; i < 16; i++) putchar('-');
    printf("\n");
    while (tab_a || tab_b)
    {
        print_int_centered(index, 8);
        printf(" | ");
        if (tab_a)
        {
            print_int_centered(*(int *)tab_a->content, 16);
            tab_a = tab_a->next;
        }
        else
            print_centered("", 16);
        printf(" | ");
        if (tab_b)
        {
            print_int_centered(*(int *)tab_b->content, 16);
            tab_b = tab_b->next;
        }
        else
            print_centered("", 16);
        printf("\n");
        index++;
    }
    for (int i = 0; i < 8; i++) putchar('-');
    printf("-+-");
    for (int i = 0; i < 16; i++) putchar('-');
    printf("-+-");
    for (int i = 0; i < 16; i++) putchar('-');
    printf("\n");
}

