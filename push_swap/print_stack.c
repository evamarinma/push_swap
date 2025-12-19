
#include "push_swap.h"

void	print_stack(t_list *stack)
{
	if (!stack)
		return ;
	while (stack != NULL)
	{
		ft_printf("%d ", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
	return ;
}