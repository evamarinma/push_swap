
#include "push_swap.h"

int	op_re_rotate_a(t_list **stack_a)
{
	t_list	*last;
	t_list	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	temp = *stack_a;
	while (temp->next->next != NULL)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_a, last);
	ft_printf("rra\n");
	get_index(stack_a);
	return (1);
}

int	op_re_rotate_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	temp = *stack_b;
	while (temp->next->next != NULL)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_b, last);
	ft_printf("rrb\n");
	get_index(stack_b);
	return (1);
}

int	op_re_rrr(t_list **stack_a, t_list **stack_b)
{
	int	re_rotate_a;
	int	re_rotate_b;

	re_rotate_a = op_re_rotate_a(stack_a);
	re_rotate_b = op_re_rotate_b(stack_b);
	ft_printf("rrr\n");
	return (re_rotate_a && re_rotate_b);
}