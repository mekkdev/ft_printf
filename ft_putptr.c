/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himekkao <himekkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 07:17:15 by himekkao          #+#    #+#             */
/*   Updated: 2026/11/17 11:34:59 by himekkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				counter;
	int				x;

	counter = 0;
	if (!ptr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	address = (unsigned long)ptr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	counter = 2;
	x = ft_puthex('x', address);
	if (x == -1)
		return (-1);
	counter += x;
	return (counter);
}
