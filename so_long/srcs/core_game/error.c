/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:29:23 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/28 13:30:44 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error(const char *msg)
{
	if(msg)
		ft_printf("%s\n", msg);
	exit(0);
}

void	show_debug(t_game *game)
{
	if (game->debug)
	{
		mlx_string_put(game->mlx_environment, game->display_window, 10, 10,
			0xFFFFFF, "DEBUG MODE!!!");
	}
}