/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:59:19 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/11 15:04:27 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_walk_left(t_game *game)
{
	int	width;
	int	height;

	game->anim.walk_l[0] = mlx_xpm_file_to_image(game->mlx, XPM_WALK_L0, &width, &height);
	game->anim.walk_l[1] = mlx_xpm_file_to_image(game->mlx, XPM_WALK_L1, &width, &height);
	game->anim.walk_l[2] = mlx_xpm_file_to_image(game->mlx, XPM_WALK_L2, &width, &height);
	game->anim.walk_l[3] = mlx_xpm_file_to_image(game->mlx, XPM_WALK_L3, &width, &height);
}

void	load_walk_right(t_game *game)
{
	int	width;
	int	height;
	
	game->anim.walk_r[0] = mlx_xpm_file_to_image(game->mlx, XPM_WALK_R0, &width, &height);
	game->anim.walk_r[1] = mlx_xpm_file_to_image(game->mlx, XPM_WALK_R1, &width, &height);
	game->anim.walk_r[2] = mlx_xpm_file_to_image(game->mlx, XPM_WALK_R2, &width, &height);
	game->anim.walk_r[3] = mlx_xpm_file_to_image(game->mlx, XPM_WALK_R3, &width, &height);
}


int walk_left_loop(t_game *game)
{
	game->anim.delay_counter++;
	if (game->anim.delay_counter >= 2000)
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
	if (game->anim.delay_counter >= 2000)
	{
		game->anim.current_frame = (game->anim.current_frame + 1) % 4;
		game->anim.delay_counter = 0;
	}
	place_graphics(game, game->anim.walk_r[game->anim.current_frame], 
		game->player.player_y, game->player.player_x);

	return (0);
}
