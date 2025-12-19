/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:44:22 by emarin-m          #+#    #+#             */
/*   Updated: 2025/10/14 11:44:24 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sep_address(char *str, char c, int j, int i)
{
	if (i == 0)
		if (str[i] != c)
			return (j);
	while (str[j])
	{
		if (str[j] == c)
		{
			while (str[j] == c)
				j++;
			return (j);
		}
		j++;
	}
	return (j);
}

static int	count_arr(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*create_substr(char *str, char c)
{
	char	*substr;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	substr = malloc(sizeof(char) * (i + 1));
	if (!substr)
	{
		free(substr);
		return (NULL);
	}
	ft_strlcpy(substr, str, i + 1);
	return (substr);
}

static void	*free_array(int i, char **array)
{
	while (i > 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		i;
	int		a;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	a = count_arr((char *)s, c);
	str_arr = malloc(((a + 1) * sizeof(char *)));
	if (!str_arr)
		return (NULL);
	while (i < a)
	{
		j = sep_address((char *)s, c, 0, i);
		s = s + j;
		str_arr[i] = create_substr((char *)s, c);
		if (!str_arr[i])
			free_array(i, str_arr);
		i++;
	}
	str_arr[a] = NULL;
	return (str_arr);
}
