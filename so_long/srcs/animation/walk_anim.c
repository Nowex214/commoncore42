/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:19 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/17 10:58:33 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int walk_left_loop(t_game *game)
{
	game->anim.delay_counter++;
	if (game->anim.delay_counter >= 7000)
	{
		game->anim.current_frame = (game->anim.current_frame + 1) % 4;
		game->anim.delay_counter = 0;
	}
	place_graphics(game, game->anim.walk_l[game->anim.current_frame], 
		game->player.player_y, game->player.player_x);
	return (0);
}

int walk_right_loop(t_game *game)
{
	game->anim.delay_counter++;
	if (game->anim.delay_counter >= 7000)
	{
		game->anim.current_frame = (game->anim.current_frame + 1) % 4;
		game->anim.delay_counter = 0;
	}
	place_graphics(game, game->anim.walk_r[game->anim.current_frame], 
		game->player.player_y, game->player.player_x);
	return (0);
}
