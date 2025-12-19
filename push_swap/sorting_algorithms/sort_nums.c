
#include "push_swap.h"

/*
If after moving all integers from stack_b to stack_a this one is not completely sorted,
final_sort() will execute ra or rra depending on the index of the smallest number
until it's on the first node of 'stack_a'.
*/

void	final_sort(t_list **stack_a)
{
	int		min_num;
	int		min_index;
	t_list	*temp;

	min_num = (*stack_a)->content;
	min_index = (*stack_a)->index;
	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->content < min_num)
		{
			min_num = temp->content;
			min_index = temp->index;
		}
		temp = temp->next;
	}
	if (min_index <= ft_lstsize(*stack_a) / 2)
	{
		while ((*stack_a)->content != min_num)
			op_rotate_a(stack_a);
		return ;
	}
		while ((*stack_a)->content != min_num)
			op_re_rotate_a(stack_a);
}

/*
takes both 'node' and its target to the top of their respective stacks.
*/

int	move_top(t_list **stack_a, t_list **stack_b, t_list *node, int len)
{
	int		a_len;
	int		target_index;
	t_list	*target_node;

	a_len = ft_lstsize(*stack_a);
	target_node = *stack_a;
	target_index = get_target(*stack_a, node->content);
	while (target_node != NULL && target_node->index != target_index)
		target_node = target_node->next;
	if (node->index <= len / 2)
		move_up(NULL, stack_b, node);
	else
		move_down(NULL, stack_b, node);
	if (target_index < a_len / 2)
		move_up(stack_a, NULL, target_node);
	else
		move_down(stack_a, NULL, target_node);
	return (1);
}

/*
Turk algorithm uses a cost-base system to find which node will require less operations
to be place at the top of stack_a. extract_b() finds the cheapest node in stack_b and
takes it to the top of stack_a.
*/

void	extract_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		min_cost;
	int		current_cost;
	t_list	*cheapest;

	temp = *stack_b;
	cheapest = temp;
	min_cost = eval_cost(*stack_a, temp, ft_lstsize(*stack_b));
	temp = temp->next;
	while (temp != NULL)
	{
		current_cost = eval_cost(*stack_a, temp, ft_lstsize(*stack_b));
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = temp;
		}
		temp = temp->next;
	}
	move_top(stack_a, stack_b, cheapest, ft_lstsize(*stack_b));
	op_push_a(stack_a, stack_b);
 	if ((*stack_a)->content > get_biggest_num((*stack_a)->next))
		op_rotate_a(stack_a);
	return ;
}

int	large_sort(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a)
		return (0);
	while (ft_lstsize(*stack_a) > 3)
		op_push_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b != NULL)
		extract_b(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		final_sort(stack_a);
	return (1);
}

int	get_sorted(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a)
		return (0);
	if (ft_lstsize(*stack_a) == 2)
	{
		sort_two(stack_a);
		return (1);
	}
	if (ft_lstsize(*stack_a) == 3)
	{
		sort_three(stack_a);
		return (1);
	}
	if (!large_sort(stack_a, stack_b))
		return (0);
	return (1);
}