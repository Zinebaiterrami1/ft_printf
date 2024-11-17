/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:30:59 by zait-err          #+#    #+#             */
/*   Updated: 2024/11/17 19:55:01 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    int i;
	int value;
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
			if(format[i] == 'd')
			{
				ft_putchar_fd(va_arg(ap, int));
			}
			i++;
			count++;
		}
		else
		{
			ft_putchar_fd(format[i]);
			count++;
			i++;
		}
	}
	va_end(ap);
	return count;
}

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

int main()
{
	int a;
	
	a = 1;
	int count = ft_printf("Voici un nombre : %d\n", a);
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