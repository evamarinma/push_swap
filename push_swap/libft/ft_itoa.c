/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:03:48 by emarin-m          #+#    #+#             */
/*   Updated: 2025/10/15 15:05:06 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static void	reverse_str(char *str, int size)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	if (str[start] == '-')
		start = 1;
	end = size - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	char	*converted_nb;
	int		size;
	int		i;

	i = 0;
	size = count_digits(n);
	converted_nb = ft_calloc(size + 1, sizeof(char));
	if (!converted_nb)
		return (NULL);
	if (n == -2147483648)
		return (free(converted_nb), ft_strdup("-2147483648"));
	if (n < 0)
	{
		converted_nb[i++] = '-';
		n = -n;
	}
	while (i < size)
	{
		converted_nb[i++] = (n % 10) + '0';
		n = n / 10;
	}
	reverse_str(converted_nb, (size));
	return (converted_nb);
}
