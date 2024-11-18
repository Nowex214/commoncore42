/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:23:04 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/18 11:03:52 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_nbr_base(size_t nbr, char *base)
{
	int	i;
	
	i = 0;
	if (nbr >= 16)
		i += ft_put_nbr_base(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
	i++;
	return (i);
}

int	ft_puthex(size_t nbr, char format)
{
	if (format == 'x')
		return (ft_put_nbr_base(nbr, "0123456789abcdef"));
	if (format == 'X')
		return (ft_put_nbr_base(nbr, "0123456789ABCDEF"));
	return (0);
}