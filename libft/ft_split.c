/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:54:34 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/28 16:35:29 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int		count;
	int		word;
	size_t	i;

	count = 0;
	word = 0;
	while (*str)
	{
		if (*str != c && word == 0)
		{
			i = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*fill_word(const char *str, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *str, char c)
{
	int		word;
	int		i;
	char	**split;

	i = 0;
	word = word_count(str, c);
	split = (char **)malloc(sizeof(char *) * (word + 1));
	if (!str || !split)
		return (NULL);
	while (*str)
	{
		if (*str != c)
		{
			split[i] = fill_word(str, c);
			if (!split[i])
				return (NULL);
			i++;
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
