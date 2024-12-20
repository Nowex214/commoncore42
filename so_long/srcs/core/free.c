/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:07:53 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/20 14:20:59 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_animations(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->anim.idle_l[i])
			mlx_destroy_image(game->mlx, game->anim.idle_l[i]);
		if (game->anim.idle_r[i])
			mlx_destroy_image(game->mlx, game->anim.idle_r[i]);
		if (game->anim.walk_l[i])
			mlx_destroy_image(game->mlx, game->anim.walk_l[i]);
		if (game->anim.walk_r[i])
			mlx_destroy_image(game->mlx, game->anim.walk_r[i]);
		if (game->anim.collectables[i])
			mlx_destroy_image(game->mlx, game->anim.collectables[i]);
		i++;
	}
}

void	destroy_map_images(t_game *game)
{
	if (game->map.ground)
		mlx_destroy_image(game->mlx, game->map.ground);
	if (game->map.wall)
		mlx_destroy_image(game->mlx, game->map.wall);
	if (game->map.door_open)
		mlx_destroy_image(game->mlx, game->map.door_open);
	if (game->map.door_close)
		mlx_destroy_image(game->mlx, game->map.door_close);
}

void	destroy_window_and_display(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.hmap)
	{
		if (game->map.map[i])
			free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}
