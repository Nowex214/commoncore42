/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:18:03 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/17 17:18:03 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *str, int i)
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