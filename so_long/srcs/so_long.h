/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:22:59 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/07 14:39:25 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define SPRITE_SIZE 96
# define KEY_ESC 65307
# define KEY_UP 122			// W
# define KEY_DOWN 115		// S
# define KEY_LEFT 113		// A
# define KEY_RIGHT 100		// D
# define KEY_INTERACT 101	// E


# define XPM_COLLECTABLE	"sprite/collectable.xpm"
# define XPM_WALL			"sprite/wall.xpm"
# define XPM_GROUND			"sprite/ground.xpm"
# define XPM_LIFE_BAR		"sprite/livebar.xpm"
# define XPM_PLAYER_RIGHT	"sprite/player_right.xpm"
# define XPM_PLAYER_LEFT	"sprite/player_left.xpm"
# define XPM_EXIT_OPEN		"sprite/open_door.xpm"
# define XPM_EXIT_CLOSE 	"sprite/close_door.xpm"


# define WIN_WIDTH 1008
# define WIN_HEIGHT 528

typedef enum e_direction
{
    DIR_UP = 1,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
}   t_direction;

typedef struct	s_map
{
	char		**map;

	int			collectibles_remaining;
	int			wmap;
	int			hmap;

	void		*ground;
	void		*wall;
	void 		*door_close;
	void		*door_open;
	void		*collectible;
	void		*player_left;
	void		*player_right;
}	t_map;

typedef struct	s_imput
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	interact;
}	t_imput;

typedef struct	s_cam
{
	int			win_width;
	int			win_height;
	int			cam_x;
	int			cam_y;
}	t_cam;

typedef struct	s_animation
{
	int		frame_count;
	int		current_frame;
	int		frame_delay;
	int		delay_counter;
	t_list	*start;
	t_list	*frames;
}	t_animation;

typedef struct	s_lifebar
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	spacing;
}	t_lifebar;

typedef struct	s_player
{
	int			mouvement;
	int			life;
	int			player_x;
	int			player_y;
	void		*life_sprite;
	char		last_direction;
	t_animation	idle_left;
	t_animation	idle_right;
}	t_player;

typedef struct	s_game
{
	void		*mlx;
	void		*win;

	int			fd;
	int			fps;

	long long	lenght;
	t_map		map;
	t_cam		cam;
	t_player	player;
	t_imput		input;

}	t_game;

void		show_life(t_game *game);
void		count_collectables(t_game *game);
void		update_camera(t_game *game);
void		handle_camera(t_game *game, int move_success);
void		find_player(t_game *game);
void		process_map(t_game *game);
void		load_images(t_game *game);
void		place_graphics(t_game *game, void *image, int height, int width);

int			handle_key(int key, t_game *game);
int 		add_graphics(t_game *game, int height, int width);
int			update_player_animation(void *param);
int			process_movement(int command, t_game *game);
int			read_map(t_game *game, char *file);
int			input(int command, t_game *game);
int			exit_game(t_game *game);
int			move_vertical(t_game *game, int direction);
int			move_horizontal(t_game *game, int direction);
int			move_to_tile(t_game *game, int x, int y);
int 		calculate_fps(void *param);
void move_player(t_game *game, int x, int y);
long long	get_time_in_ms(void);

#endif
