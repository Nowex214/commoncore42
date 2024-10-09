/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:30:25 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/01 22:30:25 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	
	if (!src)
		return (NULL);	
	if (dest < src)
	{
		i = 0;
		while(i < len)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
		return (dest);
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		}
		return (dest);
	}
}
/*
int	main(void)
{
	char src[] = "la mamie elle appelle à 22h30 normal!";
	char dest[35];

	printf("input: %s\n", src);
	ft_memmove(dest,src,strlen(src) + 1);
	printf("output: %s\n", dest);

	ft_memmove(src + 6, src, 5);
	printf("test: %s\n", src);
	return (0);
}
*/