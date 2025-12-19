/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:55:51 by emarin-m          #+#    #+#             */
/*   Updated: 2025/10/01 12:55:55 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*new_str;
	size_t			i;
	int				j;

	new_str = (unsigned char *)s;
	i = 0;
	j = 0;
	while (i < n)
	{
		new_str[j] = c;
		i++;
		j++;
	}
	return (s);
}
