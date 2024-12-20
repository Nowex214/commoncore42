/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:50:13 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/20 17:58:31 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_move_collectables(t_game *game)
{
	char	*text;
	char	*coll_text;

	text = ft_itoa(game->player.mouvement);
	coll_text = ft_itoa(game->map.collectibles_remaining);
	if (!text || !coll_text)
		return ;
	mlx_string_put(game->mlx, game->win, 180, 55, 0xFFFFFF, coll_text);
	mlx_string_put(game->mlx, game->win, 95, 55, 0xFFFFFF, text);
	free (text);
	free (coll_text);
}
