/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:48:40 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/28 17:01:04 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if (ft_isalpha(i) || ft_isdigit(i))
		return (1);
	return (0);
}
/*
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("output:%d", ft_isalnum(av[1][0]));
	return (0);
}
*/
