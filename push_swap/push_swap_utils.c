
#include "push_swap.h"

int	init_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
	return (1);
}

int	parse_input(t_list **stack_a, char **argv)
{
	int		i;
	char	**temp_arg;

	i = 1;
	while (argv[i])
	{
		temp_arg = ft_split(argv[i], ' ');
		if (!temp_arg)
			return (free_stacks(NULL, stack_a));
		if (!is_valid_num(temp_arg))
			return (free_arr(temp_arg), free_stacks(stack_a, NULL));
		if (!fill_stack(temp_arg, stack_a))
			return (free_arr(temp_arg), free_stacks(stack_a, NULL));
		free_arr(temp_arg);
		i++;
	}
	return (1);
}
