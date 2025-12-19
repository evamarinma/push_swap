
#include "push_swap.h"

int	get_smallest_num(t_list *stack_a)
{
	int		smallest;
	t_list	*temp;

	temp = stack_a;
	smallest = stack_a->content;
	while (temp != NULL)
	{
		if (temp->content < smallest)
			smallest = temp->content;
		temp = temp->next;
	}
	return (smallest);
}

int	get_smallest_index(t_list *stack_a)
{
	t_list	*smallest;
	int		target;
	int		target_index;

	smallest = stack_a;
	target_index = smallest->index;
	target = get_smallest_num(stack_a);
	while (smallest != NULL && smallest->content != target)
		smallest = smallest->next;
	target_index = smallest->index;
	return (target_index);
}
