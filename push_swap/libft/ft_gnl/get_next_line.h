/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:09:36 by emarin-m          #+#    #+#             */
/*   Updated: 2025/11/09 18:09:42 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

char	*ft_strchr_gnl(char *s, int c);
char	*strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
char	*read_next(int fd, char **line);
char	*free_content(char **s1, char **s2, char **s3);
char	*get_output(char *s);
char	*save_reminder(char **output, char **full_line, char **reminder);
int		count_until_new(char *temp);

#endif
