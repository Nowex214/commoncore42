/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:32:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/12 18:02:34 by ehenry           ###   ########.fr       */
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

int can_move_to_tile(t_game *game, int x, int y)
{
	char	tile;

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

int	move_to_tile(t_game *game, int x, int y)
{
	if (can_move_to_tile(game, x, y))
	{
		move_player(game, x, y);
		return (1);
	}
	return (0);
}

