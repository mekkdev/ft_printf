/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himekkao <himekkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 07:17:15 by himekkao          #+#    #+#             */
/*   Updated: 2026/11/17 07:35:08 by himekkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int		i;
	char	tab[12];
	int		counter;

	counter = 0;
	i = 0;
	while (n > 9)
	{
		tab[i++] = (n % 10) + '0';
		n = n / 10;
	}
	tab[i] = n + '0';
	while (i >= 0)
	{
		if (write(1, &tab[i--], 1) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}
