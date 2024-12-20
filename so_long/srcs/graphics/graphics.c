/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:52:54 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/20 17:56:24 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	place_graphics(t_game *game, void *image, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, image,
		(width * SPRITE_SIZE) - game->cam.cam_x,
		(height * SPRITE_SIZE) - game->cam.cam_y);
}

int add_graphics(t_game *game, int height, int width)
{
	place_graphics(game, game->map.ground, height, width);
	if (game->map.map[height][width] == '1' && game->map.wall)
		place_graphics(game, game->map.wall, height, width);
	else if (game->map.map[height][width] == '0' && game->map.ground)
		place_graphics(game, game->map.ground, height, width);
	else if (game->map.map[height][width] == 'E' && game->map.door_close)
	{
		if (game->map.collectibles_remaining != 0)
			place_graphics(game, game->map.door_close, height, width);
		else
			place_graphics(game, game->map.door_open, height, width);
	}
	else if (game->map.map[height][width] == 'X' && game->map.enemy)
		place_graphics(game, game->map.enemy, height, width);
	mlx_put_image_to_window(game->mlx, game->win, game->map.hud, 25, 25);
	return (0);
}
