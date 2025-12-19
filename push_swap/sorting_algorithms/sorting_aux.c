
#include "push_swap.h"

int	get_biggest_num(t_list *stack_a)
{
	int		biggest;
	t_list	*temp;

	temp = stack_a;
	biggest = stack_a->content;
	while (temp != NULL)
	{
		if (temp->content > biggest)
			biggest = temp->content;
		temp = temp->next;
	}
	return (biggest);
}

void	move_up(t_list **stack_a, t_list **stack_b, t_list *node)
{
	if (stack_a != NULL)
	{
		if (node->index == 0)
			return ;
		while (node != *stack_a)
			op_rotate_a(stack_a);
	}
	else
	{
		if (node->index == 0)
			return ;
		while (node != *stack_b)
			op_rotate_b(stack_b);
	}
	return ;
}

void	move_down(t_list **stack_a, t_list **stack_b, t_list *node)
{
	if (stack_a != NULL)
	{
		while (node->index != 0)
			op_re_rotate_a(stack_a);
	}
	else
	{
		while (node->index != 0)
			op_re_rotate_b(stack_b);
	}
	return ;
}

/*
Turk algorithm works with targets. You want to find the smallest bigger number than 'reference'
in stack_a, so later on you can place the 'reference' number right before its target. In other
words, given a list of "3 9 7" and a reference of "6", there are 2 numbers bigger than "6", "7",
and "9". You would take "7" as "6"'s target, so after sorting the list would look like "3 6 7 9",
not "3 7 6 9" if you took "9" as target.

'reference' could be already bigger than any number in 'stack_a', so you'd need to find the smallest
integer in 'stack_a' and place reference right before that node.
*/

int	get_target(t_list *stack_a, int reference)
{
	int		target;
	int		target_index;
	t_list	*temp;

	temp = stack_a;
	target = INT_MAX;
	target_index = 0;
	while (temp != NULL)
	{
		if (temp->content > reference && temp->content <= target)
		{
			target = temp->content;
			target_index = temp->index;
		}
		temp = temp->next;
	}
	if (target == INT_MAX)
		target_index = get_smallest_index(stack_a);
	return (target_index);
}

/*
eval_cost() returns the number of movements required to take 'node' to the top
of 'stack_a'
*/

int	eval_cost(t_list *stack_a, t_list *node, int len)
{
	int		a_cost;
	int		b_cost;
	int		a_len;
	int		target;

	a_cost = 0;
	b_cost = 0;
	a_len = ft_lstsize(stack_a);
	target = get_target(stack_a, node->content);
	if (node->index <= len / 2)
		b_cost = node->index;
	else
		b_cost = len - node->index;
	if (target <= a_len / 2)
		a_cost = target;
	else
		a_cost = a_len - target;
	return (a_cost + b_cost);
}
