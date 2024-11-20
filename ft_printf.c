/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:30:59 by zait-err          #+#    #+#             */
/*   Updated: 2024/11/20 14:10:05 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_put_hexa(ptr, 'x');
	}
	return (count);
}

int	format_check(va_list ap, char c)
{
	int				count;
	unsigned long	ptr;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'c')
		count += ft_putchar((char)va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'u')
		count += ft_put_unsigned_int(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_put_hexa(va_arg(ap, unsigned int), c);
	else if (c == 'p')
	{
		ptr = va_arg(ap, unsigned long int);
		count += ft_ptr(ptr);
	}
	else
		count += ft_putchar('%') + ft_putchar(c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	ap;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '\0')
			count = -1;
		else if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			count += format_check(ap, s[i]);
		}
		else if (s[i] != '%' && s[i])
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	test_ft_printf();
}
