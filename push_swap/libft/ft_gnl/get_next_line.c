/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:09:55 by emarin-m          #+#    #+#             */
/*   Updated: 2025/11/09 18:09:57 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_next(int fd, char **line)
{
	char	*temp_buff;
	ssize_t	read_buff;

	temp_buff = malloc(BUFFER_SIZE + 1);
	if (!temp_buff)
		return (NULL);
	temp_buff[0] = '\0';
	read_buff = 1;
	while (!ft_strchr_gnl(temp_buff, '\n') && read_buff > 0)
	{
		read_buff = read(fd, temp_buff, BUFFER_SIZE);
		if (!temp_buff || read_buff == 0)
			return (free(temp_buff), *line);
		if (read_buff < 0)
		{
			free(temp_buff);
			return (free(*line), NULL);
		}
		temp_buff[read_buff] = '\0';
		*line = strjoin_gnl(*line, temp_buff);
		if (!*line)
			return (free(temp_buff), NULL);
	}
	free(temp_buff);
	return (*line);
}

char	*get_output(char *s)
{
	char	*new;
	int		i;
	int		j;

	j = -1;
	i = count_until_new(s);
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	while (++j < i)
		new[j] = s[j];
	new[j] = '\0';
	return (new);
}

char	*save_reminder(char **output, char **full_line, char **reminder)
{
	char	*new_rem;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*reminder)
		free(*reminder);
	if (!output || !full_line)
		return (free_content(output, full_line, NULL));
	while ((*full_line)[i] && (*full_line)[i] != '\n')
		i++;
	if ((*full_line)[i])
		i++;
	if (!(*full_line)[i])
		return (NULL);
	new_rem = malloc(ft_strlen(*full_line + i) + 1);
	if (!new_rem)
		return (free_content(output, full_line, reminder));
	while ((*full_line)[i])
		new_rem[j++] = (*full_line)[i++];
	new_rem[j] = '\0';
	return (new_rem);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*output;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(1);
	if (!buffer)
		return (free_content(&reminder, NULL, NULL));
	buffer[0] = '\0';
	if (reminder)
		buffer = strjoin_gnl(buffer, reminder);
	buffer = read_next(fd, &buffer);
	if (!buffer)
		return (free_content(&reminder, &buffer, NULL));
	if (buffer[0] == '\0')
		return (free_content(&reminder, &buffer, NULL));
	output = NULL;
	output = get_output(buffer);
	if (!output)
		return (free_content(&reminder, &buffer, &output));
	reminder = save_reminder(&output, &buffer, &reminder);
	free_content(&buffer, NULL, NULL);
	return (output);
}
