/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:26:26 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/20 17:29:24 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void update_camera(t_game *game)
{
	int player_x = game->player.player_x * SPRITE_SIZE;
	int player_y = game->player.player_y * SPRITE_SIZE;
	if (player_x < game->cam.cam_x)
		game->cam.cam_x -= WIN_WIDTH;
	else if (player_x >= game->cam.cam_x + WIN_WIDTH)
		game->cam.cam_x += WIN_WIDTH;

	if (player_y < game->cam.cam_y)
		game->cam.cam_y -= WIN_HEIGHT;
	else if (player_y >= game->cam.cam_y + WIN_HEIGHT)
		game->cam.cam_y += WIN_HEIGHT;
	if (game->cam.cam_x < 0)
		game->cam.cam_x = 0;
	else if (game->cam.cam_x > (game->map.wmap * SPRITE_SIZE) - WIN_WIDTH)
		game->cam.cam_x = (game->map.wmap * SPRITE_SIZE) - WIN_WIDTH;

	if (game->cam.cam_y < 0)
		game->cam.cam_y = 0;
	else if (game->cam.cam_y > (game->map.hmap * SPRITE_SIZE) - WIN_HEIGHT)
		game->cam.cam_y = (game->map.hmap * SPRITE_SIZE) - WIN_HEIGHT;
}

void handle_camera(t_game *game, int move_success)
{
	int player_x = game->player.player_x * SPRITE_SIZE;
	int player_y = game->player.player_y * SPRITE_SIZE;

	if (move_success)
	{
		if (player_x < game->cam.cam_x || player_x >= game->cam.cam_x + WIN_WIDTH ||
			player_y < game->cam.cam_y || player_y >= game->cam.cam_y + WIN_HEIGHT)
		{
			update_camera(game);
		}
		mlx_clear_window(game->mlx, game->win);
		process_map(game);
	}
}
