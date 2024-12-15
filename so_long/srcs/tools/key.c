/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:58:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/13 01:47:33 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int key_pressed(int key, t_game *game)
{
	if (key == KEY_LEFT)
		game->input.left = 1;
	if (key == KEY_RIGHT)
		game->input.right = 1;
	if (key == KEY_UP)
		game->input.up = 1;
	if (key == KEY_DOWN)
		game->input.down = 1;
	return (0);
}

int key_release(int key, t_game *game)
{
	if (key == KEY_LEFT)
		game->input.left = 0;
	if (key == KEY_RIGHT)
		game->input.right = 0;
	if (key == KEY_UP)
		game->input.up = 0;
	if (key == KEY_DOWN)
		game->input.down = 0;
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
}
