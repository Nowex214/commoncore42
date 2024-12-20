/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:57:36 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/20 18:11:56 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->map.ground = mlx_xpm_file_to_image(game->mlx, XPM_GROUND, &width, &height);
	game->map.wall = mlx_xpm_file_to_image(game->mlx, XPM_WALL, &width, &height);
	game->map.enemy = mlx_xpm_file_to_image(game->mlx, XPM_ENEMY, &width, &height);
	game->map.door_close = mlx_xpm_file_to_image(game->mlx, XPM_DOOR_CLOSE, &width, &height);
	game->map.door_open = mlx_xpm_file_to_image(game->mlx, XPM_DOOR_OPEN, &width, &height);
	game->map.hud = mlx_xpm_file_to_image(game->mlx, XPM_HUD, &width, &height);
	game->map.dead = mlx_xpm_file_to_image(game->mlx, XPM_DEAD, &width, &height);
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
