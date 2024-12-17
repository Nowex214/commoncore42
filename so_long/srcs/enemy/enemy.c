/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:31:11 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/17 13:17:20 by ehenry           ###   ########.fr       */
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
	game->enemies_count = count_enemies(game);
	game->enemies = malloc(sizeof(t_enemy) * game->enemies_count);
	if (!game->enemies)
		return ;
	find_enemies(game);
}

void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	new_x;
	int	new_y;

	new_x = enemy->x;
	new_y = enemy->y;
	if (enemy->direction == 0)
		new_x--;
	else if (enemy->direction == 1)
		new_x++;
	else if (enemy->direction == 2)
		new_y--;
	else if (enemy->direction == 3)
		new_y++;
	printf("Enemy at (%d, %d) trying to move to (%d, %d)\n", enemy->x, enemy->y, new_x, new_y);
	if (can_enemies_move(game, new_x, new_y))
	{
		game->map.map[enemy->y][enemy->x] = '0';
		enemy->x = new_x;
		enemy->y = new_y;
		game->map.map[new_y][new_x] = 'X';
		printf("Enemy moved to (%d, %d)\n", new_x, new_y);
	}
	else
	{
		enemy->direction = (enemy->direction + 1) % 4;
		printf("Enemy changed direction to %d\n", enemy->direction);
	}
}


void	move_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemies_count)
	{
		move_enemy(game, &game->enemies[i]);
		i++;
	}
}
