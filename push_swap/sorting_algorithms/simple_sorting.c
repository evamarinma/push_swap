
#include "push_swap.h"

int	sort_two(t_list **stack_a)
{
	if (!stack_a || !*stack_a)
		return (0);
	if (!is_sorted(*stack_a))
		op_swap_a(stack_a);
	return (1);
}

int	sort_three(t_list **stack_a)
{
	if (((*stack_a)->content < (*stack_a)->next->content)
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		{
			op_re_rotate_a(stack_a);
			if ((*stack_a)->content > (*stack_a)->next->content)
				op_swap_a(stack_a);
		}
	else if (((*stack_a)->content < (*stack_a)->next->content)
		&& ((*stack_a)->content > (*stack_a)->next->next->content))
		op_re_rotate_a(stack_a);
	if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->next->content < (*stack_a)->next->next->content))
		{
			if ((*stack_a)->content < (*stack_a)->next->next->content)
				op_swap_a(stack_a);
			else
				op_rotate_a(stack_a);
		}
	if (((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content))
		{
			op_rotate_a(stack_a);
			op_swap_a(stack_a);
		}
	return (1);
}
