/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:49:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/22 13:43:07 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		*(unsigned char *)(ptr + i) = (unsigned char) value;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
	char str[50] = "nique ta mère simon";

	printf("output: %s\n",str);
	ft_memset(str, 'A', 5);
	printf("output: %s\n",str);
	return (0);
}
*/