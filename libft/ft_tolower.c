/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:30:50 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/02 22:30:50 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int i)
{
	if (i >= 'A' && i <= 'Z')
		return (i + 32);
	return (i);
}
/*
int	main(void)
{
	char c = 'B';
	printf("%c -> %c\n",c, ft_tolower(c));
	c = 'z';
	printf("%c -> %c\n", c, ft_tolower(c));
	return (0);
}
*/
