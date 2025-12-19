/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:13:33 by emarin-m          #+#    #+#             */
/*   Updated: 2025/10/06 15:13:36 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concatenated;
	char	*str1;
	char	*str2;
	size_t	size;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	concatenated = malloc(size);
	if (!concatenated)
		return (NULL);
	ft_strlcpy(concatenated, str1, ft_strlen(str1) + 1);
	ft_strlcat(concatenated, str2, size);
	return (concatenated);
}
