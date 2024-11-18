/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:30:59 by zait-err          #+#    #+#             */
/*   Updated: 2024/11/18 22:36:14 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format_check(va_list ap, char c)
{
	int count;
	
	count = 0;
	if(c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if(c == 'c')
		count += ft_putchar((char)va_arg(ap, int));
	else if(c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == '%')
		count += ft_putchar('%');
	else if(c == 'u')
		count += ft_put_unsigned_int(va_arg(ap, unsigned int));
	else if(c == 'x' || c == 'X')
		count += ft_put_hexa(va_arg(ap, unsigned long int), c);
	else if(c == 'p')
	{
		unsigned long ptr = va_arg(ap, unsigned long);
		if(!ptr)
		count += ft_putstr("(nil)");
		else
		{
		count += ft_putstr("0x");
		count += ft_put_hexa(ptr, 'x');
		}
	}
	return(count);
}

int ft_printf(const char *s, ...)
{
	int count;
	int i;
	va_list ap;
	
	if(!s)
		return(0);
	if (write(1, 0, 0) == -1)
        return (-1);
	va_start(ap, s);
	while (s[i])
	{
		if(s[i] == '%' && s[i + 1] != '\0')
			count += format_check(ap, s[++i]);
		else if(s[i] != '%' && s[i])
			count += ft_putchar(s[i]);
		i ++;
	}
	va_end(ap);
	return (count);
}

int main()
{
	int a;
	char c;
	char *ss;
	unsigned int u;

	u = -5500;
	ss = "NAME !";
	c = 'z';
	a = 13516;
	int hexa = 270;
	char *s ;
	s = NULL;
	int counter = ft_printf("hello test %i %c %s %%%% %u %x %X %p\n", a, c, ss, u, hexa, hexa, &a);
	//ft_printf("%d %h", ss);
	ft_printf("Caractères imprimés : %d\n", counter);
	ft_printf("%s\n", s);
	printf("--------------------------------------------\n");
	int count = printf("hello test %i %c %s %%%% %u %x %X %p\n", a, c, ss, u, hexa, hexa, &a);  
	printf("Caractères imprimés : %d\n", count);	
	printf("%s, %p\n", s, s);
}
