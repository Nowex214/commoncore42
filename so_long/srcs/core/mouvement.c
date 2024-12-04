/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:32:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/04 21:47:33 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	can_move_to_tile(t_game *game, int x, int y)
{
	char tile;

	tile = game->map.map[y][x];
	if (tile == 'E' && game->map.collectibles_remaining <= 0)
	{
		ft_printf("WIN!!!");
		exit_game(game);
		return (0);
	}
	if (tile == '0' || tile == 'C')
		return (1);
	return (0);
}

void	move_player(t_game *game, int x, int y)
{
	char tile;

	tile = game->map.map[y][x];
	if (tile == 'C')
		game->map.collectibles_remaining--;
	game->map.map[game->y_axis][game->x_axis] = '0';
	add_graphics(game, game->y_axis, game->x_axis);
	game->x_axis = x;
	game->y_axis = y;
	game->map.map[y][x] = 'P';
	add_graphics(game, game->y_axis, game->x_axis);
	game->player.mouvement++;
}

int	move_to_tile(t_game *game, int x, int y)
{
	if (can_move_to_tile(game, x, y))
	{
		move_player(game, x, y);
		return (1);
	}
	return (0);
}

int	input(int command, t_game *game)
{
	int	move_success;

	move_success = process_movement(command, game);
	handle_camera(game, move_success);
	return (1);
}
