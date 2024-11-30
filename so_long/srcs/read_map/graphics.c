/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:32:25 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/29 21:28:38 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sprite(t_game *game)
{
	int	i;
	int	j;

	game->wall = mlx_xpm_file_to_image(game->mlx_environment, "sprite/wall.xpm", &i, &j);
	game->ground = mlx_xpm_file_to_image(game->mlx_environment, "sprite/ground.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx_environment, "sprite/exit.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx_environment, "sprite/player.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx_environment, "sprite/collectable.xpm", &i, &j);
}

void	add_graphics(t_game *game)
{
	size_t	x;
	size_t	y;

	if (!game->map || !game->mlx_environment || !game->display_window)
		return;
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

