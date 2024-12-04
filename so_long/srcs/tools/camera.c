/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:26:26 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/04 21:47:42 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void update_camera(t_game *game)
{
	int player_x;
	int player_y;

	player_x = game->x_axis * SPRITE_SIZE;
	player_y = game->y_axis * SPRITE_SIZE;
	game->cam.cam_x = (player_x / WIN_WIDTH) * WIN_WIDTH;
	game->cam.cam_y = (player_y / WIN_HEIGHT) * WIN_HEIGHT;
	if (game->cam.cam_x < 0)
		game->cam.cam_x = 0;
	if (game->cam.cam_x > (game->map.wmap * SPRITE_SIZE) - WIN_WIDTH)
		game->cam.cam_x = (game->map.wmap * SPRITE_SIZE) - WIN_WIDTH;

	if (game->cam.cam_y < 0)
		game->cam.cam_y = 0;
	if (game->cam.cam_y > (game->map.hmap * SPRITE_SIZE) - WIN_HEIGHT)
		game->cam.cam_y = (game->map.hmap * SPRITE_SIZE) - WIN_HEIGHT;
}

void handle_camera(t_game *game, int move_success)
{
	int player_x;
	int player_y;

	if (move_success)
	{
		player_x = game->x_axis * SPRITE_SIZE;
		player_y = game->y_axis * SPRITE_SIZE;
		if (player_x < game->cam.cam_x || player_x >= game->cam.cam_x + WIN_WIDTH ||
			player_y < game->cam.cam_y || player_y >= game->cam.cam_y + WIN_HEIGHT)
		{
			update_camera(game);
		}
		mlx_clear_window(game->mlx, game->win);
		process_map(game);
		ft_printf("movement: %d\n", game->player.mouvement);
		ft_printf("collectible: %d\n", game->map.collectibles_remaining);
	}
}
