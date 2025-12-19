/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:11:26 by emarin-m          #+#    #+#             */
/*   Updated: 2025/06/24 15:01:52 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	og_dest_len;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)src;
	while (dst[i] != '\0')
	{
		i++;
	}
	og_dest_len = i;
	if (i >= size)
	{
		return (size + ft_strlen(str));
	}
	while (str[j] != '\0' && i < size - 1)
	{
		dst[i] = str[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (og_dest_len + ft_strlen(str));
}
