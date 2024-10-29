/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:35:47 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/29 15:01:47 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len + 1);
	return (dest);
	free(dest);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "Hello World";
	str2 = ft_strdup(str1);
	if (str2 == NULL)
	{
		fprintf (stderr,"memory allocation failed\n");
		return (1);
	}	
	printf("output : %s\n", str2);
	free(str2);
	return (0);
}*/
