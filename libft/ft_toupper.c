/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:22:16 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/02 22:22:16 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int	ft_toupper(int i)
{
	if (i >= 'a' && i <= 'z')
		return (i - 32);
	return (i);
}
/*
int	main(void)
{
	char c = 'b';
	printf("%c -> %c\n", c, ft_toupper(c));
	c = 'Z';
	printf("%c -> %c\n", c, ft_toupper(c));
	return (0);
}
*/