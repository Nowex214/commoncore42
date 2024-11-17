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

static int	ft_va_list(va_list args, char format)
{
    int	len;

	len = 0;

    if (format == 's')
        len += ft_putstr(va_arg(args, char *));
    else if (format == 'c')
        len += ft_putchar(va_arg(args, int));
    else if (format == 'd' || format == 'i')
        len += ft_putnbr(va_arg(args, int));
    else if (format == 'u')
        len += ft_putunbr(va_arg(args, unsigned int));
    else if (format == 'p')
        len += ft_putpointer(va_arg(args, void *));
    else if (format == 'x' || format == 'X')
        len += ft_puthex(va_arg(args, unsigned int), format);
    else if (format == '%')
        len += ft_putchar('%');
	return (len);
}

static int	ft_format(va_list args, const char *format)
{
	int	len;
	int j;

	len = 0;
	j = 0;
	while (format[j])
	{
		if (format[j] == '%' && format[j + 1] && ft_strchr("scdiupxX%", format[j + 1]))
		{
			j++;
			len += ft_va_list(args, format[j]);
		}
		else
			len += ft_putchar(format[j]);
		j++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
    int		i;
    va_list	args;

    i = 0;
    va_start(args, format);
    i = ft_format(args, format);
    va_end(args);
    return (i);
}