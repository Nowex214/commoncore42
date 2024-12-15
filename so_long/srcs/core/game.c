/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:05:17 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/14 19:06:45 by ehenry           ###   ########.fr       */
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
	load_collectables(game);
	load_door(game);
	update_camera(game);
}

int	initialize_game(t_game *game, char **av)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	if (!read_map(game, av[1]))
	{
		cleanup_game(game);
		return (0);
	}
	if (game->map.wmap * 96 > WIN_WIDTH)
		game->cam.win_width = WIN_WIDTH;
	else
		game->cam.win_width = game->map.wmap * 96;
	if (game->map.hmap * 96 > WIN_HEIGHT)
		game->cam.win_height = WIN_HEIGHT;
	game->win = mlx_new_window(game->mlx, game->cam.win_width, game->cam.win_height, "So_long ehenry");
	if (!game->win)
	{
		cleanup_game(game);
		return (0);
	}
	game->player.last_direction = 'R';
	load_game(game);
	return (1);
}

int	exit_game(t_game *game)
{
	int	line;
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->anim.collectables[i])
			mlx_destroy_image(game->mlx, game->anim.collectables[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (game->anim.idle_l[i])
			mlx_destroy_image(game->mlx, game->anim.idle_l[i]);
		if (game->anim.idle_r[i])
			mlx_destroy_image(game->mlx, game->anim.idle_r[i]);
		i++;
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	line = 0;
	while (line < game->map.hmap)
	{
		free(game->map.map[line]);
		line++;
	}
	free(game->map.map);
	exit(0);
}

void	cleanup_game(t_game *game)
{
	int	i;

	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	i = 0;
	while (i < 32)
	{
		if (game->anim.collectables[i])
			mlx_destroy_image(game->mlx, game->anim.collectables[i]);
		if (game->anim.idle_l[i])
			mlx_destroy_image(game->mlx, game->anim.idle_l[i]);
		if (game->anim.idle_r[i])
			mlx_destroy_image(game->mlx, game->anim.idle_r[i]);
		if (game->anim.walk_l[i])
			mlx_destroy_image(game->mlx, game->anim.walk_l[i]);
		if (game->anim.walk_r[i])
			mlx_destroy_image(game->mlx, game->anim.walk_r[i]);
		if (game->anim.door[i])
			mlx_destroy_image(game->mlx, game->anim.door[i]);
		i++;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
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
