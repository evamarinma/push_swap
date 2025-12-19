/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:35:57 by emarin-m          #+#    #+#             */
/*   Updated: 2025/11/17 11:36:01 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_address_hex(unsigned long n)
{
	char	c;
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		i += get_address_hex(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_get_address(void *address)
{
	int	i;

	if (!address)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i = 2;
	i += get_address_hex((unsigned long)address);
	return (i);
}
