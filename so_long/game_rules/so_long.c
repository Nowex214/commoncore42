/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:33:04 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/25 01:33:04 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_game));
	map_read(&game, av);
	game.mlx_environment = mlx_init();
	game.display_window = mlx_new_window(game.mlx_environment, (game.widthmap * 20), (game.heightmap * 40), "test");
	sprite(&game);
	add_graphics(&game);
	mlx_loop(game.mlx_environment);
}