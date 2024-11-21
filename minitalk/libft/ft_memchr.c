/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:31:45 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/30 15:44:59 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memB, int chrC, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)memB;
	while (i < len)
	{
		if (str[i] == (char)chrC)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	const char memB[] = "Hello, world!";
	char ch = 'w';
	char *res;

	res = memchr(memB, ch, sizeof(memB));
	if (res != NULL)
		printf("Le caractère '%c' a été trouvé à 
	la position: %ld\n", ch, res - memB);
	else
		printf("le caractère '%c' n'a pas été trouvé.\n", ch);
	return (0);
}
*/