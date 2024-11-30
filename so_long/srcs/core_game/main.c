/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:02:14 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/29 21:02:14 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game = malloc(sizeof(t_game));
	if (!game)
		return (error("Error: memory allocation failed"));
	ft_bzero(game, sizeof(t_game));
	if (!game)
		return (error("Memory allocation failed"));
	if (check_debug_option(argc, argv))
		return (error("Try: ./so_long <map_file>.ber"));
	if (!verification(game, argv[1]))
		return (error("Error: invalid map"));
	game->heightmap = count_map_lines(game, argv[1]);
	if (game->heightmap == 0)
		return (1);
	if (!read_map(game, argv[1]))
		return (1);
	if (game)
		add_graphics(game);
	add_graphics(game);
	if (!game->mlx_environment)
		return (error("Error: mlx_environment initialization failed"));
	mlx_loop(game->mlx_environment);
	return (0);
}
