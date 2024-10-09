/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:52:15 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/01 21:52:15 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!src)
		return (NULL);
	while (i < len)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
}
/*
int		main(void)
{
	char str1[50] = "nique ta mère simon";
	char str2[50] = "nique ta mère oleg";

	printf("output: %s\n",str1);
	ft_memcpy(str1, str2, 50);
	printf("output: %s\n",str1);
	return (0);
}
*/