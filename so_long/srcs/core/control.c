/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:32:56 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/07 14:39:25 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_vertical(t_game *game, int direction)
{
	int	new_y;

	new_y = game->player.player_y + direction;
	if (new_y < 0 || new_y >= game->map.hmap)
		return (0);
	return (move_to_tile(game, game->player.player_x, new_y));
}

int	move_horizontal(t_game *game, int direction)
{
	int	new_x;

	new_x = game->player.player_x + direction;
	if (new_x < 0 || new_x >= game->map.wmap)
		return (0);
	return (move_to_tile(game, new_x, game->player.player_y));
}

int	process_movement(int command, t_game *game)
{
	if (command == KEY_ESC)
		exit_game(game);
	else if (command == KEY_UP)
		return (move_vertical(game, -1));
	else if (command == KEY_DOWN)
		return (move_vertical(game, 1));
	else if (command == KEY_LEFT)
	{
		game->player.last_direction = 'L';
		return (move_horizontal(game, -1));
	}
	else if (command == KEY_RIGHT)
	{
		game->player.last_direction = 'R';
		return (move_horizontal(game, 1));
	}
	return (0);
}


int	handle_key(int key, t_game *game)
{
	if (key == KEY_UP)
		game->input.up = 1;
	else if (key == KEY_DOWN)
		game->input.down = 1;
	else if (key == KEY_LEFT)
		game->input.left = 1;
	else if (key == KEY_RIGHT)
		game->input.right = 1;
	else if (key == KEY_INTERACT)
		game->input.interact = 1;
	if (key == KEY_UP)
		game->input.up = 0;
	else if (key == KEY_DOWN)
		game->input.down = 0;
	else if (key == KEY_LEFT)
		game->input.left = 0;
	else if (key == KEY_RIGHT)
		game->input.right = 0;
	else if (key == KEY_INTERACT)
		game->input.interact = 0;
	process_movement(key, game);
	return (0);
}

