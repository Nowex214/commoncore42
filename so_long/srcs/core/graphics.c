/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:52:54 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/07 14:39:11 by ehenry           ###   ########.fr       */
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

int add_graphics(t_game *game, int height, int width)
{
	place_graphics(game, game->map.ground, height, width);
	if (game->map.map[height][width] == '1' && game->map.wall)
		place_graphics(game, game->map.wall, height, width);
	else if (game->map.map[height][width] == 'C' && game->map.collectible)
		place_graphics(game, game->map.collectible, height, width);
	else if (game->map.map[height][width] == 'E' && game->map.door_close)
		place_graphics(game, game->map.door_close, height, width);

	else if (game->map.map[height][width] == 'P')
	{
		if (game->map.map[game->player.player_y][game->player.player_x] == 'P')
		{
			game->map.map[game->player.player_y][game->player.player_x] = '0';
			place_graphics(game, game->map.ground, game->player.player_y, game->player.player_x);
		}
		game->player.player_y = height;
		game->player.player_x = width;
		if (game->player.last_direction == 'L' && game->map.player_left)
			place_graphics(game, game->map.player_left, height, width);
		else if (game->player.last_direction == 'R' && game->map.player_right)
			place_graphics(game, game->map.player_right, height, width);
	}
	return (0);
}


void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->map.ground = mlx_xpm_file_to_image(game->mlx, XPM_GROUND, &width, &height);
	game->map.wall = mlx_xpm_file_to_image(game->mlx, XPM_WALL, &width, &height);
	game->map.player_left = mlx_xpm_file_to_image(game->mlx, XPM_PLAYER_LEFT, &width, &height);
	game->map.player_right = mlx_xpm_file_to_image(game->mlx, XPM_PLAYER_RIGHT, &width, &height);
	game->map.door_open = mlx_xpm_file_to_image(game->mlx, XPM_EXIT_OPEN, &width, &height);
	game->map.door_close = mlx_xpm_file_to_image(game->mlx, XPM_EXIT_CLOSE, &width, &height);
	game->map.collectible = mlx_xpm_file_to_image(game->mlx, XPM_COLLECTABLE, &width, &height);
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