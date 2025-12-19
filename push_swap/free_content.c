
#include "push_swap.h"

void	free_arr(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}

void	ft_lstclear_int(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

int	free_stacks(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a)
		ft_lstclear_int(stack_a);
	if (stack_b && *stack_b)
		ft_lstclear_int(stack_b);
	return (0);
}