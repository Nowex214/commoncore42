/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:07:29 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/18 12:16:19 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_va_list(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 's')
		len += ft_putstr(args);
	else if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(args);
	else if (format == 'u')
		len += ft_putunbr(args);
	else if (format == 'p')
		len += ft_putpointer(va_arg(args, void *));
	else if (format == 'x' || format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i += ft_va_list(args, *format);
		}
		else
		{
			ft_putchar(*format);
			i++;
		}
		format++;
	}
	va_end(args);
	return (i);
}
