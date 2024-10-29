/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:15:02 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/28 17:04:56 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!s2[0])
		return ((char *)&s1[i]);
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < len)
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    const char *haystack = "Hello, world!";
    const char *needle = "l";
    size_t len = 12;
    char *result;

    result = ft_strnstr(haystack, needle, len);
    
    if (result != NULL)
        printf("Sous-chaîne trouvée : \"%s\"\n", result);
    else
        printf("Sous-chaîne non trouvée dans la 
	limite de %zu caractères.\n", len);

    return 0;
}
*/
