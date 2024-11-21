/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:27:06 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/21 11:30:38 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(va_list args)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		str++;
		len++;
	}
	return (len);
}
