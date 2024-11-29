/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:21:12 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/28 14:50:55 by ehenry           ###   ########.fr       */
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

typedef struct s_game
{
	int		fd;
	int		map_fd;
	size_t	heightmap;
	size_t	widthmap;

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

	t_list	*lst_map;
}	t_game;

//Function for the read_map
int		chek_debug_option(int ac, char **av);
int		verification(t_game *game, char *file_path);
int		count_map_lines(t_game *game, char *file_path);
int		read_map(t_game *game, char *file_path);
int		map_check(t_game *game);

//Function for the display file
void	sprite(t_game *game);
void	add_graphics(t_game *game);

//Function for the error file
int		error(const char *msg);
#endif