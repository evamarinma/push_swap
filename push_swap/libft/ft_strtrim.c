/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:06:59 by emarin-m          #+#    #+#             */
/*   Updated: 2025/10/08 13:07:02 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_match(char *str1, char *str2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str1[i])
	{
		k = 0;
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j])
			{
				k = 1;
				break ;
			}
			j++;
		}
		if (k == 0)
			break ;
		i++;
	}
	return (i);
}

static int	second_match(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	k;

	i = 0;
	len = ft_strlen(str1);
	while (i < len)
	{
		k = 0;
		j = 0;
		while (str2[j])
		{
			if (str1[len - i - 1] == str2[j])
			{
				k = 1;
				break ;
			}
			j++;
		}
		if (k == 0)
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			j;
	char			*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = first_match((char *)s1, (char *)set);
	j = second_match((char *)s1, (char *)set);
	if ((i + j >= ft_strlen((char *)s1)))
	{
		trimmed = malloc(1);
		if (!trimmed)
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = malloc(ft_strlen((char *)s1) - i - j + 1);
	if (!trimmed)
		return (NULL);
	if (i + j >= ft_strlen((char *)s1))
		trimmed[0] = '\0';
	ft_strlcpy(trimmed, (char *)s1 + i, ft_strlen((char *)s1) - i - j + 1);
	return (trimmed);
}
