/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:32:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/11 09:18:47 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	move_player(t_game *game, int x, int y)
{
	char	old_tile;

	old_tile = game->map.map[game->player.player_y][game->player.player_x];
	game->map.map[game->player.player_y][game->player.player_x] = '0';
	game->player.player_x = x;
	game->player.player_y = y;
	if (game->map.map[y][x] == 'C')
		game->map.collectibles_remaining--;
	game->map.map[y][x] = 'P';
	if (game->player.last_direction == 'L' && game->anim.idle_l[0] != NULL)
		place_graphics(game, game->anim.idle_l[game->anim.current_frame], y, x);
	else if (game->player.last_direction == 'R' && game->anim.idle_r[0] != NULL)
		place_graphics(game, game->anim.idle_r[game->anim.current_frame], y, x);
	add_graphics(game, game->player.player_y, game->player.player_x);
	game->player.mouvement++;
}
