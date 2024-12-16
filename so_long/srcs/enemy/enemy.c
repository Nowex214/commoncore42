/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:31:11 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/16 15:44:59 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_enemies(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'X')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	set_enemy_data(t_enemy *enemy, int x, int y)
{
	enemy->x = x;
	enemy->y = y;
	enemy->direction = 0;
}

void	init_enemies(t_game *game)
{
	int	x;
	int	y;
	int	i;

	game->enemies_count = count_enemies(game->data);
	game->enemies = malloc(sizeof(t_game) * (game->enemies_count));
	
}

