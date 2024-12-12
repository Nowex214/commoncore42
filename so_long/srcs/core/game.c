/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:05:17 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/12 18:08:19 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_game(t_game *game)
{
	count_collectables(game);
	find_player(game);
	load_idle_left(game);
	load_idle_right(game);
	load_walk_left(game);
	load_walk_right(game);
	update_camera(game);
}

int	initialize_game(t_game *game, char **av)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	if (!read_map(game, av[1]))
		return (0);
	if (game->map.wmap * 96 > WIN_WIDTH)
		game->cam.win_width = WIN_WIDTH;
	else
		game->cam.win_width = game->map.wmap * 96;
	if (game->map.hmap * 96 > WIN_HEIGHT)
		game->cam.win_height = WIN_HEIGHT;
	game->win = mlx_new_window(game->mlx, game->cam.win_width, game->cam.win_height, "So_long ehenry");
	game->player.last_direction = 'R';
	load_game(game);
	return (1);
}

int	exit_game(t_game *game)
{
	int	line;

	line = 0;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	while (line < game->map.hmap)
		free(game->map.map[line++]);
	free(game->map.map);
	exit(0);
}

int setup_game(t_game *game)
{
	int height;

	load_images(game);
	height = 0;
	while (height < game->map.hmap)
	{
		int width = 0;
		while (game->map.map[height][width])
		{
			if (add_graphics(game, height, width) == -1)
				return (-1);
			width++;
		}
		height++;
	}
	mlx_hook(game->win, 17, 0, (void *)exit_game, game);
	return (0);
}