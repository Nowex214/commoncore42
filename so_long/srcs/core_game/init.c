/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:42:54 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/29 21:42:54 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(char **av, t_game *game)
{
	game->mlx_environment = mlx_init();
	game->widthmap = -1;
	game->heightmap = -1;
	if (av[2] && ft_strcmp(av[2], "DEBUG=1") == 0)
		game->debug = 1;
	else
		game->debug = 0;
	game->player = ft_calloc(sizeof(t_player), 1);
	if (!game->player)
		exit(EXIT_FAILURE);
	game->player->jumpstate = 0;
	
}