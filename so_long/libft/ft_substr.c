/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:08:40 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/29 15:24:40 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
	{
		str = malloc(sizeof(char));
		if (!s)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > i - start)
		len = i - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
/*
int	main(void)
{
	int start = 2;
	size_t len = 10;
	char str[] = "TG Gabrielle tu parles trop";
	printf("output:%s\n", ft_substr(str, start, len));
    return (0);
}
*/
