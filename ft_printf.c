/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:30:59 by zait-err          #+#    #+#             */
/*   Updated: 2024/11/18 16:48:52 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    int i;
	int count;

	va_list ap;
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format [i] != '\0')
	{
		if(format[i] == '%')
		{
			i++;
			if(format[i] == 'd' || format[i] == 'i')
			{
				count += ( va_arg(ap, int));
			}
			else if(format[i] == 'c')
			{
				count += ft_putchar((char)va_arg(ap, int));
			}
			else if(format[i] == 's')
			{
				count += ft_putstr(va_arg(ap, char *));
			}
			else if (format[i] == '%')
			{
				count += ft_putchar('%');
			}
			else if(format[i] == 'u')
			{
				count += ft_put_unsigned_int(va_arg(ap, unsigned int));
			}
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}

int main()
{
	int a;
	char c;
	char *s;
	unsigned int u;

	u = -5500;
	s = "NAME !";
	c = 'z';
	a = 1;
	int count = ft_printf("%i %c %s %%%% %u\n", a, c, s, u);
    printf("Caractères imprimés : %d\n", count);
}

// int sum(int count, ...)
// {
//     int i;
//     int s;

//     s = 0;
//     va_list args;
//     va_start(args, count);
    
//     for(i = 0; i < count; i ++)
//     {
//        int x = va_arg(args, int);
//        s += x;
//     }
//     va_end(args);
//     return(s);
// }

// int main()
// {
//     printf("%d\n", sum(5, 1, 2, 3, 4, 1));
// }

// int ft_strlen(char *str)
// {
// 	int i;

// 	i = 0;
// 	if(!str)
// 		return (0);
// 	while (str[i] != '\0')
// 	{
// 		i ++;
// 	}
// 	return (i);
// }
// void	ft_putnbr(int n)
// {
// 	if (n == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 		return ;
// 	}
// 	if (n < 0)
// 	{
// 		ft_putchar('-');
// 		n = -n;
// 	}
// 	if (n >= 10)
// 	{
// 		ft_putnbr(n / 10);
// 		ft_putchar((n % 10) + 48);
// 	}
// 	else
// 		ft_putchar(n + 48);
// }

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putstr(char *s)
// {
// 	int	i;

// 	if (!s)
// 		return ;
// 	i = 0;
// 	while (s[i])
// 	{
// 		ft_putchar(s[i]);
// 		i++;
// 	}
// }
