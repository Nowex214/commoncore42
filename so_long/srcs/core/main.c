/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:15:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/16 11:15:50 by ehenry           ###   ########.fr       */
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
	cleanup_and_exit(&game);
	return (0);
}
