/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:31:04 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/11 14:57:11 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int update_player_animation(void *param)
{
	t_game		*game = NULL;

	game = (t_game *)param;
	if (game->input.left)
		game->player.last_direction = 'L';
	else if (game->input.right)
		game->player.last_direction = 'R';

	return (0);
}

void	load_idle_left(t_game *game)
{
	int	width;
	int	height;

	game->anim.idle_l[0] = mlx_xpm_file_to_image(game->mlx, XPM_IDLE_L0, &width, &height);
	game->anim.idle_l[1] = mlx_xpm_file_to_image(game->mlx, XPM_IDLE_L1, &width, &height);
	game->anim.idle_l[2] = mlx_xpm_file_to_image(game->mlx, XPM_IDLE_L2, &width, &height);
	game->anim.idle_l[3] = mlx_xpm_file_to_image(game->mlx, XPM_IDLE_L3, &width, &height);
}

void	load_idle_right(t_game *game)
{
	int	width;
	int	height;
	
	game->anim.idle_r[0] = mlx_xpm_file_to_image(game->mlx, XPM_IDLE_R0, &width, &height);
	game->anim.idle_r[1] = mlx_xpm_file_to_image(game->mlx, XPM_IDLE_R1, &width, &height);
	game->anim.idle_r[2] = mlx_xpm_file_to_image(game->mlx, XPM_IDLE_R2, &width, &height);
	game->anim.idle_r[3] = mlx_xpm_file_to_image(game->mlx, XPM_IDLE_R3, &width, &height);
}


int idle_left_loop(t_game *game)
{
	game->anim.delay_counter++;
	if (game->anim.delay_counter >= 2000)
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
	if (game->anim.delay_counter >= 2000)
	{
		game->anim.current_frame = (game->anim.current_frame + 1) % 4;
		game->anim.delay_counter = 0;
	}
	place_graphics(game, game->anim.idle_r[game->anim.current_frame], 
		game->player.player_y, game->player.player_x);

	return (0);
}
