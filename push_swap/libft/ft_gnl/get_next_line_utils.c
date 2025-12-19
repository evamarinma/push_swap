/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:10:11 by emarin-m          #+#    #+#             */
/*   Updated: 2025/11/09 18:10:20 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strchr_gnl(char *s, int c)
{
	char	find;
	int		i;

	find = (char)c;
	i = 0;
	while (s[i] != find && s[i])
		i++;
	if (s[i] == find)
		return (&s[i]);
	if (find == '\0')
		return (&s[i]);
	return (NULL);
}

char	*strjoin_gnl(char *s1, char *s2)
{
	char	*concatenated;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concatenated = malloc (s1_len + s2_len + 1);
	if (!concatenated)
		return (free(s1), NULL);
	while (i < s1_len)
	{
		concatenated[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		concatenated[i++] = s2[j++];
	concatenated[s1_len + s2_len] = '\0';
	free(s1);
	return (concatenated);
}

char	*free_content(char **s1, char **s2, char **s3)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
	return (NULL);
}

int	count_until_new(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}
