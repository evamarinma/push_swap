/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:37:10 by emarin-m          #+#    #+#             */
/*   Updated: 2025/10/08 11:37:14 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str1;
	char	*str2;
	int		i;
	int		len;

	str1 = (char *)s;
	len = ft_strlen(str1);
	str2 = malloc(len + 1);
	i = 0;
	if (!str2)
		return (NULL);
	while (i < len)
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
