/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:30:56 by zait-err          #+#    #+#             */
/*   Updated: 2024/11/18 21:11:27 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		i += 11;
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar((n % 10) + 48);
	}
	else
		i += ft_putchar(n + 48);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_unsigned_int(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_put_unsigned_int(n / 10);
		i += ft_putchar((n % 10) + 48);
	}
	else
		i += ft_putchar(n + 48);
	return (i);
}

int	ft_put_hexa(unsigned long n, char format)
{
	int		i;
	char	*str;

	i = 0;
	if (format == 'X')
		str = "0123456789ABCDEF";
	else if (format == 'x')
		str = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_put_hexa(n / 16, format);
		i += ft_putchar(str[n % 16]);
	}
	else
	{
		i += ft_putchar(str[n]);
	}
	return (i);
}
