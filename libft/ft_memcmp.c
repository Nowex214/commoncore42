/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:59:34 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/28 16:28:56 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pt1, const void *pt2, size_t len)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = (const unsigned char *)pt1;
	s2 = (const unsigned char *)pt2;
	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char b1[] = "Hello, world!";
	const char b2[] = "Hello, there!";
	size_t	len = 5;
	int	res;

	res = memcmp(b1, b2, len);
	if (res == 0)
		printf("Les %zu premiers octets des 
			deux blocks sont identiques.\n", len);
	else if (res < 0)
		printf("le premier bloc est inférieur au 
			deuxième dans les %zu premiers octets.\n", len);
	else
		printf("Le premier bloc est supérieur au 
			deuxième dans les %zu premiers octets.\n", len);
	return (0);
}
*/
