/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:07:29 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/17 17:07:29 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_va_list(va_list args, char *format, int len)
{
	int	j;

	j = 0;
	len = 0;
	while (format[j])
	{
		if (format[j] == '%' && format[j + 1] && ft_strchr("scdiupxX%", format[j + 1]))
		{
			j++;
			if (format[j] == 's')
				len += ft_putstr(args);
			else if (format[j] == 'c')
				len += ft_putchar(va_arg(args, int));
			else if (format[j] == 'd' || format[j] == 'i')
				len += ft_putnbr(va_arg(args, int));
			else if (format[j] == 'u')
				len += ft_putunbr(va_arg(args, int));
			else if (format[j] == 'p')
				len += ft_putpointer(va_arg(args, void *));
			else if (format[j] == 'x' == format[j] == 'X')
				len += ft_puthex(va_arg(args, int), format);
			else if (format[j] == '%')
				len += ft_putchar('%');
			j++;
		}
		else
		{
			len += ft_putchar(format[j]);
			j++;
		}
	} 
}

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	args;

	i = 0;
	va_start(args, format);
	ft_va_list(args, format, &i);
	va_end(args);
	return (i);
}