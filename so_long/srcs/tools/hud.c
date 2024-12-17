/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:50:13 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/17 13:35:16 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	display_move(t_game *game, int command)
{
	int	move_success;
	char	*text;

	text = ft_itoa(game->player.mouvement);
	move_success = control(command, game);
	if (move_success)
	{
		mlx_string_put(game->mlx, game->win, 10, 40, 0xFFFFFF, text);
	}
	return(game->player.mouvement);
}
