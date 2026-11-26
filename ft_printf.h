/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himekkao <himekkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 07:07:30 by himekkao          #+#    #+#             */
/*   Updated: 2026/11/19 12:25:06 by himekkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int n);
int		ft_puthex(char c, unsigned long n);
int		ft_putptr(void *ptr);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);

#endif
