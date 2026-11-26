/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himekkao <himekkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 07:17:15 by himekkao          #+#    #+#             */
/*   Updated: 2026/11/19 12:30:22 by himekkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(char c, unsigned long n)
{
	char	*base;
	char	tab[21];
	int		i;
	int		counter;

	counter = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	while (n >= 16)
	{
		tab[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	tab[i] = base[n];
	while (i >= 0)
	{
		if (write(1, &tab[i--], 1) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}
