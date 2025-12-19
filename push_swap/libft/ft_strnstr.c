/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:47:28 by emarin-m          #+#    #+#             */
/*   Updated: 2025/10/03 12:47:34 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	char	*to_find;
	size_t	i;
	size_t	j;

	str = (char *)big;
	to_find = (char *)little;
	i = 0;
	if (*to_find == '\0')
		return (str);
	while (i < len && str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while ((i + j) < len && j < ft_strlen(to_find)
				&& str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
