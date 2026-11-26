/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himekkao <himekkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 07:09:59 by himekkao          #+#    #+#             */
/*   Updated: 2026/10/20 09:03:19 by himekkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_sign(long *num, int *counter)
{
	if (*num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		*num = -(*num);
		*counter = 1;
	}
	return (0);
}

int	ft_putnbr(int n)
{
	int		i;
	char	tab[12];
	long	num;
	int		counter;

	num = n;
	counter = 0;
	if (check_sign(&num, &counter) == -1)
		return (-1);
	i = 0;
	while (num > 9)
	{
		tab[i++] = (num % 10) + '0';
		num = num / 10;
	}
	tab[i] = num + '0';
	while (i >= 0)
	{
		if (write(1, &tab[i--], 1) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}
