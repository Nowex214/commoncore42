/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:31:01 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/29 13:19:30 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_num(int nb)
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

static void	define_nb(int i, char *array, int *index)
{
	if (i >= 10)
		define_nb(i / 10, array, index);
	array[(*index)++] = (i % 10) + 48;
}

char	*ft_itoa(int n)
{
	int		j;
	char	*ptr;

	j = 0;
	ptr = ft_calloc(1, (ft_len_num(n) + 1));
	if (!ptr)
		return (NULL);
	if (n == -2147483648)
	{
		ft_memcpy(ptr, "-2147483648", 12);
		return (ptr);
	}
	if (n < 0)
	{
		ptr[j] = '-';
		j++;
		n *= -1;
	}
	define_nb(n, ptr, &j);
	ptr[j] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	int	a = 214451255;
	printf("output:%s\n",ft_itoa(a));
	return (0);
}
*/