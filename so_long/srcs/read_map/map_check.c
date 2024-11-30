/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:59:09 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/29 22:59:09 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_check(t_game *game)
{
	char	*line;
	size_t	i;

	i = 0;
	while ((line = get_next_line(game->fd)) != NULL)
	{
		if ((size_t)ft_strlen(line) != game->widthmap)
			return (error("Error: width map incorrect"));
		if (i == 0 || i == game->heightmap - 1)
		{
			if (line[0] != '1' || line[game->widthmap - 1] != '1')
				return (error("Error: map not inclosed by walls"));
		}
		free(line);
		i++;
	}
	return (1);
}