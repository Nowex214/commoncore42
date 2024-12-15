/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:28:31 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/13 01:51:33 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void update_player_animation(t_game *game)
{

	if (game->player.is_moving)
	{
		if (game->player.last_direction == 'L')
			walk_left_loop(game);
		else if (game->player.last_direction == 'R')
			walk_right_loop(game);
	}
	else
	{
		if (game->player.last_direction == 'L')
			idle_left_loop(game);
		else if (game->player.last_direction == 'R')
			idle_right_loop(game);
	}
}


int	is_player_moving(t_game *game)
{
	if (game->input.up || game->input.down || game->input.left || game->input.right)
	{
		return (1);
	}
	return (0);
}