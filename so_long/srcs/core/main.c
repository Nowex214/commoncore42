/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:15:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/04 21:47:28 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int initialize_game(t_game *game, char **av)
{
	ft_memset(game, 0, sizeof(t_game));
	if (!read_map(game, av[1]))
		return (0);
	count_collectables(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);

	if (game->map.wmap * 96 > WIN_WIDTH)
		game->cam.win_width = WIN_WIDTH;
	else
		game->cam.win_width = game->map.wmap * 96;

	if (game->map.hmap * 96 > WIN_HEIGHT)
		game->cam.win_height = WIN_HEIGHT;
	game->win = mlx_new_window(game->mlx, game->cam.win_width, game->cam.win_height, "So_long ehenry");
	game->cam.cam_x = 0;
	game->cam.cam_y = 0;
	find_player(game);
	update_camera(game);
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
	load_images(game);

	int height = 0;
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

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (0);
	if (!initialize_game(&game, av))
		return (0);
	setup_game(&game);
	mlx_key_hook(game.win, input, &game);
	mlx_loop_hook(game.mlx, calculate_fps, &game);
	mlx_loop(game.mlx);
}
