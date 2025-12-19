/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:53:06 by emarin-m          #+#    #+#             */
/*   Updated: 2025/10/02 16:53:15 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	find;
	unsigned char	*str;
	size_t			i;

	find = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n && str[i] != find)
		i++;
	if (i < n)
		return (&str[i]);
	return (NULL);
}
