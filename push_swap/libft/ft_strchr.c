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

char	*ft_strchr(const char *s, int c)
{
	char	find;
	char	*str;
	int		i;

	find = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != find && str[i])
		i++;
	if (str[i] == find)
		return (&str[i]);
	if (find == '\0')
		return (&str[i]);
	return (NULL);
}
