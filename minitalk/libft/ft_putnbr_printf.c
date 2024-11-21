/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:01:35 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/21 11:30:24 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
		len += ft_digit_count(nbr / 10);
	ft_putchar((nbr % 10) + '0');
	len++;
	return (len);
}

int	ft_putnbr(va_list args)
{
	int	len;
	int	nbr;

	nbr = va_arg(args, int);
	len = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
		return (len);
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		len++;
	}
	len += ft_digit_count(nbr);
	return (len);
}
