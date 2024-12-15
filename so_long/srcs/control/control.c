/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:32:56 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/14 00:38:27 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int control(int keycode, t_game *game)
{
	game->player.is_moving = 0;

	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_UP)
		game->player.is_moving = move_vertical(game, -1);
	else if (keycode == KEY_DOWN)
		game->player.is_moving = move_vertical(game, 1);
	else if (keycode == KEY_LEFT)
	{
		game->player.last_direction = 'L';
		game->player.is_moving = move_horizontal(game, -1);
	}
	else if (keycode == KEY_RIGHT)
	{
		game->player.last_direction = 'R';
		game->player.is_moving = move_horizontal(game, 1);
	}
	else if (keycode == KEY_IDLE)
		game->player.is_moving = 0;
	return (game->player.is_moving);
}

int	input(int command, t_game *game)
{
	int	move_success;

	move_success = control(command, game);
	if (move_success)
	{
		ft_printf("Movement: %d\n", game->player.mouvement);
		ft_printf("Collectables: %d\n", game->map.collectibles_remaining);
	}
	handle_camera(game, move_success);
	return (1);
}
