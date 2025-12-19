/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:55:15 by emarin-m          #+#    #+#             */
/*   Updated: 2025/10/06 11:55:17 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated_mem;
	void	*zero_mem;
	size_t	mem_size;

	mem_size = nmemb * size;
	allocated_mem = malloc(mem_size);
	if (!allocated_mem)
		return (NULL);
	zero_mem = ft_memset(allocated_mem, 0, mem_size);
	if (zero_mem)
		return (zero_mem);
	return (NULL);
}
