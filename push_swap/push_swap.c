
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (error_output());
	if (!init_stacks(&stack_a, &stack_b))
		return (error_output());
	if (!parse_input(&stack_a, argv))
		return (free_stacks(&stack_a, &stack_b), error_output());
	if (!check_duplicated(stack_a))
		return (free_stacks(&stack_a, &stack_b), error_output());
	if (!count_args(stack_a))
		return (free_stacks(&stack_a, &stack_b), error_output());
	if (is_sorted(stack_a))
		return (free_stacks(&stack_a, &stack_b), 0);
	innit_index(&stack_a, &stack_b);
	if (!get_sorted(&stack_a, &stack_b))
		return (free_stacks(&stack_a, &stack_b), error_output());
	free_stacks(&stack_a, &stack_b);
	return (0);
}

