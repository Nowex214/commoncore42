/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:17:52 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/16 10:25:38 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int collectabes_loop(t_game *game)
{
	int	y;
	int	x;

	game->anim.delay_counter++;
	if (game->anim.delay_counter >= 5000)
	{
		game->anim.current_frame = (game->anim.current_frame + 1) % 4;
		game->anim.delay_counter = 0;
	}
	y = 0;
	while (y < game->map.hmap)
	{
		x = 0;
		while (x < game->map.wmap)
		{
			if (game->map.map[y][x] == 'C')
				place_graphics(game, game->anim.collectables[game->anim.current_frame], y, x);
			x++;
		}
		y++;
	}
	return (0);
}

int	door_loop(t_game *game)
{
	game->anim.delay_counter++;
	if (game->anim.delay_counter >= 5000)
	{
		game->anim.current_frame = (game->anim.current_frame + 1) % 4;
		game->anim.delay_counter = 0;
	}
	return (0);
}
