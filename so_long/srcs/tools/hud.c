/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:50:13 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/04 22:59:56 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	show_life(t_game *game)
{
	t_lifebar	lifebar;

	lifebar.x = 900;
	lifebar.y = 50;
	lifebar.width = 192;
	lifebar.height = 96;

	game->player.life_sprite = mlx_xpm_file_to_image(game->mlx, "sprite/livebar.xpm", &lifebar.width, &lifebar.height);
	mlx_put_image_to_window(game->mlx, game->win, game->player.life_sprite, lifebar.x, lifebar.y);
}