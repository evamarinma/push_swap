/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:35:23 by emarin-m          #+#    #+#             */
/*   Updated: 2025/09/30 12:35:26 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	long			nb;
	unsigned char	*str;
	int				neg;

	i = 0;
	nb = 0;
	neg = 1;
	str = (unsigned char *)nptr;
	while (is_space(str[i]) || str[i] == '-' || str[i] == '+'
		|| ft_isdigit(str[i]))
	{
		if ((str[i] == '-' || str[i] == '+') && !(ft_isdigit(str[i + 1])))
			break ;
		if (str[i] == '-')
			neg = -1;
		if (ft_isdigit(str[i]))
			nb = (nb * 10) + (str[i] - '0');
		if (ft_isdigit(str[i]) && (!ft_isdigit(str[i + 1])))
			break ;
		i++;
	}
	return ((int)nb * neg);
}
