/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:52:54 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/04 21:47:23 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	place_graphics(t_game *game, void *image, int height, int width)
{
	if (!image)
	{
		ft_putstr_fd("Error: Trying to render a NULL image\n", 2);
		return;
	}
	if (!game->mlx || !game->win)
	{
		ft_putstr_fd("Error: MiniLibX context or window is NULL\n", 2);
		return;
	}
	mlx_put_image_to_window(game->mlx, game->win, image,
		(width * SPRITE_SIZE) - game->cam.cam_x,
		(height * SPRITE_SIZE) - game->cam.cam_y);
}

int	add_graphics(t_game *game, int height, int width)
{

		place_graphics(game, game->map.ground, height, width);
		if (game->map.map[height][width] == '1' && game->map.wall)
			place_graphics(game, game->map.wall, height, width);
		else if (game->map.map[height][width] == 'C' && game->map.collectible)
		{
			place_graphics(game, game->map.collectible, height, width);
		}
		else if (game->map.map[height][width] == 'E' && game->map.exit)
			place_graphics(game, game->map.exit, height, width);
		else if (game->map.map[height][width] == 'P' && game->map.player)
		{
			place_graphics(game, game->map.player, height, width);
			game->y_axis = height;
			game->x_axis = width;
	}
	return (0);
}


void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->map.ground = mlx_xpm_file_to_image(game->mlx,
		"sprite/ground.xpm", &width, &height);
	game->map.wall = mlx_xpm_file_to_image(game->mlx,
		"sprite/wall.xpm", &width, &height);
	game->map.player = mlx_xpm_file_to_image(game->mlx,
		"sprite/player_right.xpm", &width, &height);
	game->map.exit = mlx_xpm_file_to_image(game->mlx,
		"sprite/exit.xpm", &width, &height);
	game->map.collectible = mlx_xpm_file_to_image(game->mlx,
		"sprite/collectable.xpm", &width, &height);
}


void	process_map(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map.hmap)
	{
		width = 0;
		while (game->map.map[height][width])
		{
			add_graphics(game, height, width);
			width++;
		}
		height++;
	}
}
