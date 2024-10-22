/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:25:08 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/21 15:31:11 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *ptr, size_t len)
{
	return (ft_memset(ptr, 0, len));
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