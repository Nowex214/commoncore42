/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:32:56 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/19 11:20:27 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int control(int keycode, t_game *game)
{
	game->player.is_moving = 0;

	if (keycode == KEY_ESC)
		cleanup_and_exit(game);
	if (keycode == KEY_UP || keycode == KEY_UP_DIR)
		game->player.is_moving = move_vertical(game, -1);
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_DIR)
		game->player.is_moving = move_vertical(game, 1);
	else if (keycode == KEY_LEFT || keycode == KEY_LEFT_DIR)
	{
		game->player.last_direction = 'L';
		game->player.is_moving = move_horizontal(game, -1);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_DIR)
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
	handle_camera(game, move_success);
	return (1);
}
