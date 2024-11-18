/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:13:50 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/18 12:18:43 by ehenry           ###   ########.fr       */
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

int	ft_putpointer(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	i += write(1, "0x", 2);
	i += ft_put_nbr_base((size_t)ptr, "0123456789abcdef");
	return (i);
}
