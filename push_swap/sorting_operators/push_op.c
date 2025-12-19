
#include "push_swap.h"

int	op_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_a || !stack_b || !*stack_b)
		return (0);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_printf("pa\n");
	get_index(stack_a);
	get_index(stack_b);
	return (1);
}

int	op_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_a || !*stack_a || !stack_b)
		return (0);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_printf("pb\n");
	get_index(stack_a);
	get_index(stack_b);
	return (1);
}