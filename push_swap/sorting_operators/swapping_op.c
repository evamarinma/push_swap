
#include "push_swap.h"

int	op_swap_a(t_list **stack_a)
{
	int	temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	temp = (*stack_a)->next->content;
	(*stack_a)->next->content = (*stack_a)->content;
	(*stack_a)->content = temp;
	ft_printf("sa\n");
	get_index(stack_a);
	return (1);
}

int	op_swap_b(t_list **stack_b)
{
	int	temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	temp = (*stack_b)->next->content;
	(*stack_b)->next->content = (*stack_b)->content;
	(*stack_b)->content = temp;
	ft_printf("sb\n");
	get_index(stack_b);
	return (1);
}

int	op_swap_ss(t_list **stack_a, t_list ** stack_b)
{
	int	result_a;
	int	result_b;

	result_a = op_swap_a(stack_a);
	result_b = op_swap_b(stack_b);
	ft_printf("ss\n");
	return (result_a && result_b);
}