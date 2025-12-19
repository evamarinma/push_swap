/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:34:34 by emarin-m          #+#    #+#             */
/*   Updated: 2025/10/02 13:34:36 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	find;
	char			*str;
	int				i;
	int				j;

	find = (unsigned char)c;
	str = (char *)s;
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == find)
			j = i;
		i++;
	}
	if (find == '\0')
		return (&str[i]);
	if ((unsigned char)str[j] == find)
		return (&str[j]);
	return (NULL);
}
