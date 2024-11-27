/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:21:12 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/27 16:37:39 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define TILE_WIDTH 40
# define TILE_HEIGHT 40

typedef struct s_game
{
	int		fd;
	size_t	heightmap;
	size_t	widthmap;
	size_t	new_capacity;
	int	map_capacity;
	
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
int		ft_error(const char *msg);
void	add_graphics(t_game *game);
void	sprite(t_game *game);

#endif