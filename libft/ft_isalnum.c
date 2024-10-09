/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student42.luxemborug.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:48:40 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/01 20:48:40 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int i)
{
	if (ft_isalpha && ft_isdigit)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("output:%d", ft_isalnum(av[1][0]));
	return (0);
}
