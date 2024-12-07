
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:15:18 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/05 18:13:47 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define SPRITE_SIZE 96

typedef struct s_animation
{
	t_list	*frames;
	t_list	*start;
	int		frame_count;
	int		frame_delay;
	int		delay_counter;
}	t_animation;

typedef struct s_player
{
	t_animation	idle_left;
	t_animation	idle_right;
	int			player_x;
	int			player_y;
	char		last_direction;
}	t_player;

typedef struct s_camera
{
	int	cam_x;
	int	cam_y;
	int	win_width;
	int	win_height;
}	t_camera;

typedef struct s_map
{
	char	**map;
	int		wmap;
	int		hmap;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_camera	cam;
}	t_game;

// Function prototypes
void preload_player_animations(t_game *game);
int render_player_animation(void *param);
int update_player_animation(void *param);
t_list *load_animation_frames(t_game *game, char *base_path, int frame_count);
void update_animation(t_animation *anim, int fps);
void free_animation(t_game *game, t_list *start);

#endif