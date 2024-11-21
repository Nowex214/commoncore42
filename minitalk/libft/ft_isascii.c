/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:49:06 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/21 14:50:39 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	return (0);
}
/*
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("output: %d", ft_isascii(av[1][0]));
	return (0);
}
*/