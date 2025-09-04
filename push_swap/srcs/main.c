#include "../includes/push_swap.h"
#include <stdlib.h>

static int		ft_isspace(char c);
static int		is_valid_integer(char *str, int *result);
static t_stack	*create_stack(void);
static int		validate_and_parse_multiple(int argc, char **argv, t_stack **stack_a);
static int		valide_and_parse_single(char *str, t_stack **stack_a);
static int		validate_and_parse(int argc, char **argv, t_stack **stack_a);
static long		ft_atol(const char *str);
static int		has_stack_duplicates(t_stack *stack);
static void		assign_indexes(t_stack *stack);
static int		get_bit(int	number, int	bit_position);
static int		get_max_bits(t_stack *stack);
static void		radix_sort(t_stack	**stack_a, t_stack **stack_b);

#include <stdio.h>

void	print_stack(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	printf("Stack A: ");
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void	print_stacks_final(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;

	printf("Stack A (top -> bottom): ");
	if (!stack_a)
		printf("(empty)");
	else
	{
		current = stack_a;
		while (current)
		{
			printf("%d ", current->value);
			current = current->next;
		}
	}
	printf("\n");

	printf("Stack B (top -> bottom): ");
	if (!stack_b)
		printf("(empty)");
	else
	{
		current = stack_b;
		while (current)
		{
			printf("%d ", current->value);
			current = current->next;
		}
	}
	printf("\n");

	if (!stack_b)
		printf("✅ Stack B is empty\n");
	else
		printf("❌ Stack B is NOT empty (%d elements)\n", stack_size(stack_b));
}

int	main(int argc, char **argv)
{
	(void)radix_sort;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (EXIT_SUCCESS);
	stack_a = NULL;
	stack_b = NULL;
	if (validate_and_parse(argc, argv, &stack_a) == EXIT_FAILURE)
	{
		write(2, "Error\n", 6);
		cleanup_and_exit(stack_a, stack_b, EXIT_FAILURE);
	}
	if (has_stack_duplicates(stack_a) == EXIT_FAILURE)
	{
		write(2, "Error\n", 6);
		cleanup_and_exit(stack_a, stack_b, EXIT_FAILURE);
	}
	assign_indexes(stack_a);
	if (is_sorted(stack_a) == EXIT_SUCCESS)
		cleanup_and_exit(stack_a, stack_b, EXIT_SUCCESS);
	size = stack_size(stack_a);
	if (size <= 5)
		sort_small(&stack_a, &stack_b, size);
	else
		optimized_sort(&stack_a, &stack_b);
	print_stacks_final(stack_a, stack_b);
	// (void)print_stacks_final;
	cleanup_and_exit(stack_a, stack_b, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static void	radix_sort(t_stack	**stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	bit;

	if (!stack_a || !*stack_a)
		return ;
	size = stack_size(*stack_a);
	max_bits = get_max_bits(*stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (get_bit((*stack_a)->index, bit) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
}

static int	get_max_bits(t_stack *stack)
{
	int	size;
	int	bits;

	size = stack_size(stack);
	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

static int get_bit(int	number, int	bit_position)
{
	return ((number >> bit_position) & 1);
}

static void	assign_indexes(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current)
	{
		current->index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}

static int	has_stack_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (compare->value == current->value)
				return (EXIT_FAILURE);
			compare = compare->next;
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

static int	validate_and_parse(int argc, char **argv, t_stack **stack_a)
{
	if (argc == 2)
		return (valide_and_parse_single(*(argv + 1), stack_a));
	else
		return (validate_and_parse_multiple(argc, argv, stack_a));
	return (EXIT_FAILURE);
}

static int	valide_and_parse_single(char *str, t_stack **stack_a)
{
	char	**args;
	char	**args_p;
	int		count;

	args = ft_split(str, ' ');
	if (!args)
		return (EXIT_FAILURE);
	count = 0;
	args_p = args;
	while (args_p[count] != NULL)
		count++;
	if (validate_and_parse_multiple(count + 1, args - 1, stack_a))
	{
		while (count-- > 0)
			free(args[count]);
		free(args);
		return (EXIT_FAILURE);
	}
	while (count-- > 0)
		free(args[count]);
	free(args);
	return (EXIT_SUCCESS);
}

static int	validate_and_parse_multiple(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	int		value;
	t_stack	*current_node;
	t_stack	*new_node;

	i = 1;
	current_node = NULL;
	*stack_a = NULL;
	while (i < argc)
	{
		if (is_valid_integer(argv[i], &value) == EXIT_FAILURE)
		{
			free_stack(*stack_a);
			*stack_a = NULL;
			return (EXIT_FAILURE);
		}
		new_node = create_stack();
		if (!new_node)
		{
			free_stack(*stack_a);
			*stack_a = NULL;
			return (EXIT_FAILURE);
		}
		new_node->value = value;
		if (*stack_a == NULL)
		{
			*stack_a = new_node;
			current_node = new_node;
		}
		else
		{
			current_node->next = new_node;
			current_node = new_node;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->index = -1;
	stack->next = NULL;
	return (stack);
}

static int	is_valid_integer(char *str, int *result)
{
	char	*original;
	long	temp;

	original = str;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (EXIT_FAILURE);
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (EXIT_FAILURE);
	temp = ft_atol(original);
	if (temp < INT_MIN || temp > INT_MAX)
		return (EXIT_FAILURE);
	*result = (int)temp;
	return (EXIT_SUCCESS);
}

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
