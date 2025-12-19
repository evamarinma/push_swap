/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin-m <emarin-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:07:34 by emarin-m          #+#    #+#             */
/*   Updated: 2025/11/13 15:07:36 by emarin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_arg(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (c == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		i = ft_get_address(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		i = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i = ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == 'x')
		i = ft_low_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		i = ft_up_hex(va_arg(args, unsigned int));
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	if (!format)
		return (-1);
	j = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '\%')
		{
			j += print_arg(format[++i], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			j++;
		}
	}
	va_end(args);
	return (j);
}

/* #include <stdio.h>

int	main(void)
{
	int	n = -42;
	if (ft_printf(NULL))
		printf("ft true\n");
	if (printf(NULL))
		printf("TRUE\n");
	printf("porcentaje: %%\n");
	return (0);
} */