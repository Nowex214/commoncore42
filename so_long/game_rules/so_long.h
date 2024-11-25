/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:21:12 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/25 17:39:01 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

typedef struct s_game
{
	int		fd;
	size_t	heightmap;
	size_t	widthmap;
	int		x_axis;
	int		y_axis;

	char	**map;

	void	*ground;
	void	*wall;
	void	*player;
	void	*collectable;
	void	*exit;
	void	*display_window;
	void	*mlx_environment;
}	t_game;

int		map_read(t_game *game, char **av);

void	add_graphics(t_game *game);
void	sprite(t_game *game);

#endif