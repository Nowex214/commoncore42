/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:16:20 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/06 21:16:20 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < len)
		i++;
	if (i == len)
		return (0);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*
int main(void)
{
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, you!";
    size_t len = 6;
    int result;

    result = strncmp(str1, str2, len);
    
    if (result == 0)
        printf("Les %zu premiers caractères des deux chaînes sont identiques.\n", len);
    else if (result < 0)
        printf("La première chaîne est plus petite que la deuxième dans les %zu premiers caractères.\n", len);
    else
        printf("La première chaîne est plus grande que la deuxième dans les %zu premiers caractères.\n", len);

    return 0;
}
*/
