/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:33:04 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/27 15:41:21 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_game(t_game *game, char **av)
{
	ft_memset(game, 0, sizeof(t_game));
	if (!map_read(game, av))
		return (ft_error("Failed to read map."));
	game->mlx_environment = mlx_init();
	if (!game->mlx_environment)
		return (ft_error("Failed to initialize MLX."));
	game->display_window = mlx_new_window(game->mlx_environment,
		(game->widthmap * TILE_WIDTH),
		(game->heightmap * TILE_HEIGHT),
		"Game Title");
	if (!game->display_window)
		return (ft_error("Failed to create window."));
	return (1);
}

static void	cleanup_game(t_game *game)
{
	size_t	i;

	i = 0;

	if (game->display_window)
		mlx_destroy_window(game->mlx_environment, game->display_window);
	if(game->map)
	{
		while (i < game->heightmap)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}
int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (1);
	if (!init_game(&game, av))
		return (1);
	sprite(&game);
	add_graphics(&game);
	mlx_loop(game.mlx_environment);
	cleanup_game(&game);
	return (0);
}
