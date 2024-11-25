/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:54:34 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/30 15:17:58 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	size_t	count;
	size_t	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

static char	*ft_malloc_word(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	ft_free(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

char	**ft_split(char const *str, char c)
{
	int		word;
	int		i;
	char	**split;

	word = ft_count_word(str, c);
	split = (char **)malloc(sizeof (char *) * (word + 1));
	if (!split || !str)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			split[i] = ft_malloc_word(str, c);
			if (!split[i++])
				return (ft_free(split, i - 1), NULL);
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	split[i] = NULL;
	return (split);
}
/*int	main()
{
	char	str[] = "LA hshshssgrosse hhhhpute sssdaxel";
	printf("output: %zu\n", ft_split(str, '\t'));
	return (1939);
}*/
