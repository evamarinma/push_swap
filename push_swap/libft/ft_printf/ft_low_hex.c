/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:50:39 by emarin-m          #+#    #+#             */
/*   Updated: 2025/11/14 15:50:41 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_low_hex(unsigned int n)
{
	char	c;
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		i += ft_low_hex(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	i++;
	return (i);
}
