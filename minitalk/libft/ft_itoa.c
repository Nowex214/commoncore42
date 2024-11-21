/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:31:01 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/30 14:33:10 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_numb(long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ptr;
	long	nb;

	nb = n;
	len = ft_len_numb(nb);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = -nb;
	}
	while (len > (n < 0))
	{
		ptr[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (ptr);
}
