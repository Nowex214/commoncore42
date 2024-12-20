/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mouv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:12:42 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/19 10:13:30 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_new_position(t_enemy *enemy, int *new_x, int *new_y)
{
	*new_x = enemy->x;
	*new_y = enemy->y;
	if (enemy->direction == 0)
		(*new_x)--;
	else if (enemy->direction == 1)
		(*new_x)++;
	else if (enemy->direction == 2)
		(*new_y)--;
	else if (enemy->direction == 3)
		(*new_y)++;
}

void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	new_x;
	int	new_y;

	get_new_position(enemy, &new_x, &new_y);
	if (can_enemies_move(game, new_x, new_y))
	{
		game->map.map[enemy->y][enemy->x] = '0';
		enemy->x = new_x;
		enemy->y = new_y;
		game->map.map[new_y][new_x] = 'X';
	}
	else
		enemy->direction = (enemy->direction + 1) % 4;

}

void	move_enemies(t_game *game)
{
	int	i;
	t_enemy *enemy;

	i = 0;
	while (i < game->enemies_count)
	{
		enemy = &game->enemies[i];
		enemy->move_timer++;
		if (enemy->move_timer >= 12000)
		{
			move_enemy(game, enemy);
			enemy->move_timer = 0;
		}
		i++;
	}
}
