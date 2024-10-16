/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student42.luxemborug.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:49:15 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/01 20:49:15 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}
/*
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("output: %d", ft_isprint(av[1][0]));
	return (0);
}
*/