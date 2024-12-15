/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:31:04 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/14 00:39:22 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int idle_left_loop(t_game *game)
{
	game->anim.delay_counter++;
	if (game->anim.delay_counter >= 3000)
	{
		game->anim.current_frame = (game->anim.current_frame + 1) % 4;
		game->anim.delay_counter = 0;
	}
	place_graphics(game, game->anim.idle_l[game->anim.current_frame], 
		game->player.player_y, game->player.player_x);
	return (0);
}

int idle_right_loop(t_game *game)
{
	game->anim.delay_counter++;
	if (game->anim.delay_counter >= 3000)
	{
		game->anim.current_frame = (game->anim.current_frame + 1) % 4;
		game->anim.delay_counter = 0;
	}
	place_graphics(game, game->anim.idle_r[game->anim.current_frame], 
		game->player.player_y, game->player.player_x);
	return (0);
}
