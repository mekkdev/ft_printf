/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himekkao <himekkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 07:17:15 by himekkao          #+#    #+#             */
/*   Updated: 2026/11/21 10:20:10 by himekkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char c, va_list args)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr((va_arg(args, int))));
	else if (c == 'c')
		return (ft_putchar(((char)va_arg(args, int))));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr((va_arg(args, void *))));
	else if (c == 'u')
		return (ft_putnbr_unsigned((va_arg(args, unsigned int))));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(c, (va_arg(args, unsigned int))));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;
	int		x;

	if (!format)
		return (-1);
	va_start(args, format);
	i = -1;
	counter = 0;
	x = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			x = handle_format(format[++i], args);
		else if (format[i] == '%')
			return (va_end(args), -1);
		else
			x = ft_putchar(format[i]);
		if (x == -1)
			return (va_end(args), -1);
		counter += x;
	}
	return (va_end(args), counter);
}
