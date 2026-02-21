/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luli2 <luli2@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:32:53 by luli2             #+#    #+#             */
/*   Updated: 2026/02/21 22:32:57 by luli2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	handle(const char format, va_list args)
{
	char	c;

	if (format == 'c')
	{
		c = (char)va_arg(args, int);
		return (ft_putchar(c));
	}
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_pointer(va_arg(args, void *)));
	else if ((format == 'i') || (format == 'd'))
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putusnbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			printed += handle(*format, args);
		}
		else
		{
			write (1, format, 1);
			printed++;
		}
		format++;
	}
	va_end(args);
	return (printed);
}
