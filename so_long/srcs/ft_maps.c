/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:32:49 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/27 16:39:21 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	width_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '\n')
		i--;
	return (i);
}

static int	append_map(t_game *game, char *line)
{
	char	**tmp;
	size_t	i;
	size_t	heightmap;

	if (!line)
	heightmap = (size_t)game->heightmap;
	if (heightmap == game->map_capacity)
	if (game->heightmap == game->map_capacity)
	{
		size_t new_capacity = (game->map_capacity == 0) ? 1 : game->map_capacity * 2;
		tmp = (char **)malloc(sizeof(char *) * new_capacity);
		if (!tmp)
		{
			ft_error("Memory allocation failed");
			return (0);
		}
		i = 0;
		while (i < game->heightmap)
		{
			tmp[i] = game->map[i];
			i++;
		}
		free(game->map);
		game->map = tmp;
		game->map_capacity = new_capacity;
	}
	game->map[game->heightmap] = line;
	game->heightmap++;
	return (1);
}
