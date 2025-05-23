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

static void print_centered(const char *str, int width)
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

static void print_int_centered(int val, int width)
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", val);
    print_centered(buf, width);
}

static void print_ints_array(t_list *tab_a, t_list *tab_b)
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

static t_list *copy_list(t_list *src)
{
	t_list	*copy = NULL;
	t_list	*current = src;
	while (current)
	{
		t_list	*new_node = ft_lstnew(malloc(sizeof(int)));
		if (!new_node)
			return (NULL);
		*(int *)new_node->content = *(int *)current->content;
		ft_lstadd_back(&copy, new_node);
		current = current->next;
	}
	return (copy);
}

int	main(int argc, char **argv)
{
	t_list	*tab_a = NULL;
	t_list	*tab_acopy = NULL;
	t_list	*tab_b = NULL;
	t_list	*tab_bcopy = NULL;
	int		steps;

	if (argc < 2)
		return (1);
	if (!argv_checker(argc, argv))
		return (ft_puterror(1));
	tab_a = create_tab_from_args(argv+1);
	if (tab_a == NULL)
		return (ft_puterror(3));

	// To delete
	tab_acopy = copy_list(tab_a);
	tab_bcopy = copy_list(tab_b);

	steps = push_swap(&tab_a, &tab_b);

	// To delete
	print_ints_array(tab_acopy, tab_bcopy);
	print_ints_array(tab_a, tab_b);
	printf("TOTAL STEPS: %d\n", steps);

	return (0);
}
