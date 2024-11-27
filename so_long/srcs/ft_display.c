/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:32:25 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/27 16:29:46 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_environment,
			game->display_window, game->player, width * 32, height * 32);
	game->y_axis = height;
	game->x_axis = width;
}
void	place_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_environment,
		game->display_window, game->collectable, width * 32, height * 32);
	game->collectable++;
}

void	sprite(t_game *game)
{
	int	i;
	int	j;

	game->wall = mlx_xpm_file_to_image(game->mlx_environment,
		"sprite/wall.xpm", &i, &j);
	game->ground = mlx_xpm_file_to_image(game->mlx_environment,
		"sprite/ground.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx_environment,
		"sprite/exit.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx_environment,
		"sprite/player.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx_environment,
		"sprite/collectable.xpm", &i, &j);
}

void	add_graphics(t_game *game)
{
	size_t	x;
	size_t	y;

	game->collectable = 0;
	x = 0;
	y = 0;
	while (game->heightmap > y)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx_environment, game->display_window, game->ground, x * 32 , y * 32);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_environment, game->display_window, game->wall, x * 32 , y * 32);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_environment, game->display_window, game->player, x * 32, y * 32);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_environment, game->display_window, game->exit, x * 32, y * 32);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_environment, game->display_window, game->collectable, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

