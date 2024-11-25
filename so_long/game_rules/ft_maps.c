/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:32:49 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/25 17:41:19 by ehenry           ###   ########.fr       */
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

	i = 0;
	if (!line)
		return (0);
	game->heightmap++;
	tmp = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!tmp)
		return (0);
	while (game->heightmap - 1 <= i)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	free(game->map);
	game->map = tmp;
	return (1);
}

int	map_read(t_game *game, char **av)
{
	char	*read;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while(1)
	{
		read = get_next_line(game->fd);
		if (!append_map(game, read))
			break ;
	}
	close (game->fd);
	game->widthmap = width_map(game->map[0]);
	return (1);
}