/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:37:43 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/02 22:37:43 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*strchr(const char *str, int i)
{
	int	j;

	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[j])
	{
		if (str[j] == (char)i)
			return ((char *)&str[j]);
		j++;
	}
	if (str[j] == (char)i)
		return ((char *)&str[j]);
	return (NULL);
}
/*
int	main(void)
{
	const char *s = "Hello, World!";
	char *result;

	result = strchr(s, 'W');
	if (result)
		printf("Found '%c' in the string: %s\n", 'W', result);
	else
		printf("Character not found.\n");

	result = strchr(s, 'x');
	if (result)
		printf("Found '%c' in the string: %s\n", 'x', result);
	else
		printf("Character not found.\n");

	return (0);
}
*/