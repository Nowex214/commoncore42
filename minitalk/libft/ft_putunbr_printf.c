/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:06:52 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/21 11:30:48 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_static(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
	{
		len += ft_putnbr_static(nbr / 10);
	}
	ft_putchar((nbr % 10) + '0');
	len++;
	return (len);
}

int	ft_putunbr(va_list args)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	nbr = va_arg(args, unsigned int);
	len += ft_putnbr_static(nbr);
	return (len);
}
