
#include "push_swap.h"

t_list	*ft_lstnew_int(int num)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = num;
	new_lst->next = NULL;
	return (new_lst);
}

int	get_index(t_list **stack)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack;
	if (!(*stack))
		return (0);
	while (temp != NULL)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
	return (1);
}

void	innit_index(t_list **stack_a, t_list **stack_b)
{
	get_index(stack_a);
	get_index(stack_b);
	return ;
}

int	fill_stack(char **data, t_list **stack_a)
{
	int		i;
	t_list	*new;

	i = 0;
	while (data[i])
	{
		new = ft_lstnew_int(ft_atoi(data[i]));
		if (!new)
			return (0);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (1);
}
