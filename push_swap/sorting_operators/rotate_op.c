
#include "push_swap.h"

int	op_rotate_a(t_list **stack_a)
{
	t_list	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_back(stack_a, temp);
	temp->next = NULL;
	ft_printf("ra\n");
	get_index(stack_a);
	return (1);
}

int	op_rotate_b(t_list **stack_b)
{
	t_list	*temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_back(stack_b, temp);
	temp->next = NULL;
	ft_printf("rb\n");
	get_index(stack_b);
	return (1);
}

int	op_rr(t_list **stack_a, t_list **stack_b)
{
	int	rotate_a;
	int	rotate_b;

	rotate_a = op_rotate_a(stack_a);
	rotate_b = op_rotate_b(stack_b);
	ft_printf("rr\n");
	return (rotate_a && rotate_b);
}