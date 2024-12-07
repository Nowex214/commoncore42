/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:32:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/07 14:39:25 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	can_move_to_tile(t_game *game, int x, int y)
{
	char tile;

	tile = game->map.map[y][x];
	if (tile == 'E' && game->map.collectibles_remaining <= 0)
	{
		ft_printf("WIN!!!");
		exit_game(game);
		return (0);
	}
	if (tile == '0' || tile == 'C')
		return (1);
	return (0);
}


int	move_to_tile(t_game *game, int x, int y)
{
	if (can_move_to_tile(game, x, y))
	{
		game->player.player_x = x;
		game->player.player_y = y;
		move_player(game, x, y);
		return (1);
	}
	return (0);
}

int	input(int command, t_game *game)
{
	int	move_success;

	move_success = process_movement(command, game);
	handle_camera(game, move_success);
	return (1);
}
void move_player(t_game *game, int x, int y)
{
    char tile;

    tile = game->map.map[game->player.player_y][game->player.player_x];
    game->map.map[game->player.player_y][game->player.player_x] = '0';
    add_graphics(game, game->player.player_y, game->player.player_x);
    game->player.player_x = x;
    game->player.player_y = y;
    tile = game->map.map[y][x];
    if (tile == 'C')
        game->map.collectibles_remaining--;
    game->map.map[y][x] = 'P';

    // Si la direction est à gauche ou à droite, on met à jour le sprite
    if (x < game->player.player_x)
        game->player.last_direction = 'L';  // Déplacement à gauche
    else if (x > game->player.player_x)
        game->player.last_direction = 'R';  // Déplacement à droite
    
    add_graphics(game, game->player.player_y, game->player.player_x);
    game->player.mouvement++;
}
