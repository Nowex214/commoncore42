/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:32:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/09 10:20:42 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	map_width(char *line)
{
	int	width;

	width = 0;
	if (line && *line)
	{
		while (line[width] != '\0' && line[width] != '\n')
			width++;
	}
	return (width);
}

static int	append_line(t_game *game, char *line)
{
	char	**new_map;
	int		i;

	if (!line)
		return (0);
	game->map.hmap++;
	new_map = malloc(sizeof(char *) * (game->map.hmap + 1));
	if (!new_map)
		return (0);
	i = 0;
	while (i < game->map.hmap - 1)
	{
		new_map[i] = game->map.map[i];
		i++;
	}
	new_map[i] = line;
	if (game->map.map)
		free(game->map.map);
	game->map.map = new_map;
	return (1);
}

int	read_map(t_game *game, char *file)
{
	char	*line;

	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("Error: Unable to open the map file.\n");
		return (0);
	}
	game->map.map = NULL;
	game->map.hmap = 0;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line || !append_line(game, line))
			break ;
	}
	close(game->fd);
	if (game->map.map)
		game->map.wmap = map_width(game->map.map[0]);
	find_player(game);
	return (game->map.map != NULL);
}
