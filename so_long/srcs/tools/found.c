/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:03:54 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/17 11:29:46 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_collectables(t_game *game)
{
	int	y;
	int	x;

	game->map.collectibles_remaining = 0;
	y = 0;
	while (y < game->map.hmap)
	{
		x = 0;
		while (x < game->map.wmap)
		{
			if (game->map.map[y][x] == 'C')
				game->map.collectibles_remaining++;
			x++;
		}
		y++;
	}
}

void	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.hmap)
	{
		x = 0;
		while (x < game->map.wmap)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.player_x = x;
				game->player.player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	find_enemies(t_game *game)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	index = 0;
	while (y < game->map.hmap)
	{
		x = 0;
		while (x < game->map.wmap)
		{
			if (game->map.map[y][x] == 'X')
			{
				set_enemy_data(&game->enemies[index], x, y);
				index++;
			}
			x++;
		}
		y++;
	}
}
