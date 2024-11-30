/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:48:13 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/29 22:48:13 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	verification(t_game *game, char *file_path)
{
	int	len;

	len = ft_strlen(file_path);
	if (len < 4)
		return (0);
	if (ft_strcmp(&file_path[len - 4], ".ber") != 0)
		return (0);
	game->map_fd = open(file_path, O_RDONLY);
	if (game->map_fd < 0)
		return (0);
	return (1);
}

int	count_map_lines(t_game *game, char *file_path)
{
	char	*line;
	int		height;

	height = 0;
	while ((line = get_next_line(game->fd)) != NULL)
	{
		height++;
		free(line);
	}
	if (height == 0)
		return (error("Error: map file is empty"));
	game->map = ft_calloc(height + 1, sizeof(char *));
	return (height);
}

int	read_map(t_game *game, char *file_path)
{
	char	*line;

	line = get_next_line(game->fd);
	if(!line)
		return(error("Error: cannot read the first line"));
	game->widthmap = ft_strlen(line);
	free(line);
	return (1);
}
