/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:15:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/14 19:00:17 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	combined_loop(void *param)
{
	t_game *game = (t_game *)param;
	update_player_animation(game);
	collectabes_loop(game);
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
	setup_hooks(&game);
	mlx_key_hook(game.win, input, &game);
	mlx_loop_hook(game.mlx, combined_loop, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
