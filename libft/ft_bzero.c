/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:25:08 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/01 21:25:08 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_bzero(void *ptr, size_t len)
{
	size_t	i;

	i = 0;
	//if (!ptr)
		//return (NULL);
	while (i < len)
	{
		*(unsigned char *)(ptr + i) = 0;
		i++;
	}
}
/*
int	main(void)
{
	char str[50] = "nique ta mère simon";
	
	printf("output: %s\n",str);
	ft_bzero(str, 5);
	printf("output: %s\n",str);
	return (0);
}
*/