
#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	t_list	*temp;
	int		sorted;

	sorted = 0;
	temp = stack_a;
	while (stack_a != NULL)
	{
		if (stack_a->content < temp->content)
			sorted++;
		temp = stack_a;
		stack_a = stack_a->next;
	}
	if (sorted == 0)
		return (1);
	return (0);
}
 
int	check_duplicated(t_list *stack_a)
{
	t_list	*temp;
	t_list	*current;

	if (!stack_a)
		return (0);
	current = stack_a;
	temp = current->next;
	while (current != NULL)
	{
		while (temp != NULL && current->content != temp->content)
		{
			temp = temp->next;
		}
		if (temp != NULL && current->content == temp->content)
			return (0);
		current = current->next;
		if (current != NULL)
			temp = current->next;
	}
	return (1);
}

int	count_args(t_list *stack_a)
{
	int		i;

	i = 0;
	if (!stack_a)
		return (0);
	while (stack_a != NULL)
	{
		i++;
		stack_a = stack_a->next;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	is_valid_int(char *nb)
{
	int	i;
	int	digit;
	int	sign;

	i = 0;
	digit = 0;
	sign = 0;
	if (nb[0] == '-' || nb[0] == '+')
	{
		sign++;
		i++;
	}
	while (nb[i])
	{
		digit++;
		i++;
	}
	if (digit > 10)
		return (0);
	if (digit == 10 &&
		((nb[0] != '-' && ft_strcmp(nb + sign, "2147483647") > 0)
		|| (nb[0] == '-' && ft_strcmp(nb + sign, "2147483648") > 0)))
		return (0);
	return (1);
}

int is_valid_num(char **data)
{
	int	i;
	int	j;

	i = 0;
	while (data[i])
	{
		j = 0;
		if ((data[i][j] == '-' || data[i][j] == '+')
			&& data[i][j + 1] >= '0' && data[i][j + 1] <= '9')
			j++;
		while (data[i][j] && data[i][j] >= '0' && data[i][j] <= '9')
			j++;
		if (data[i][j])
			return (0);
		if (!is_valid_int(data[i]))
			return (0);
		i++;
	}
	return (1);
}
