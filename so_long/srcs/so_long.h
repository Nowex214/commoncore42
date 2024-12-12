/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:22:59 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/12 18:24:31 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define SPRITE_SIZE 96
# define KEY_ESC 65307
# define KEY_UP    122  // Z
# define KEY_DOWN  115  // S
# define KEY_LEFT  113  // Q
# define KEY_RIGHT	100  // D
# define KEY_INTERACT 101	// E


# define XPM_COLLECTABLE	"sprite/collectable.xpm"
# define XPM_WALL			"sprite/wall.xpm"
# define XPM_GROUND			"sprite/ground.xpm"
# define XPM_LIFE_BAR		"sprite/livebar.xpm"
# define XPM_EXIT_OPEN		"sprite/open_door.xpm"
# define XPM_EXIT_CLOSE 	"sprite/close_door.xpm"

# define XPM_WALK_R0	"sprite/player/walk_right/1.xpm"
# define XPM_WALK_R1	"sprite/player/walk_right/2.xpm"
# define XPM_WALK_R2	"sprite/player/walk_right/3.xpm"
# define XPM_WALK_R3	"sprite/player/walk_right/4.xpm"

# define XPM_WALK_L0	"sprite/player/walk_left/1.xpm"
# define XPM_WALK_L1	"sprite/player/walk_left/2.xpm"
# define XPM_WALK_L2	"sprite/player/walk_left/3.xpm"
# define XPM_WALK_L3	"sprite/player/walk_left/4.xpm"

# define XPM_IDLE_L0	"sprite/player/idle_left/1.xpm"
# define XPM_IDLE_L1	"sprite/player/idle_left/2.xpm"
# define XPM_IDLE_L2	"sprite/player/idle_left/3.xpm"
# define XPM_IDLE_L3	"sprite/player/idle_left/4.xpm"

# define XPM_IDLE_R0	"sprite/player/idle_right/1.xpm"
# define XPM_IDLE_R1	"sprite/player/idle_right/2.xpm"
# define XPM_IDLE_R2	"sprite/player/idle_right/3.xpm"
# define XPM_IDLE_R3	"sprite/player/idle_right/4.xpm"


# define WIN_WIDTH 1008
# define WIN_HEIGHT 528


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
	void	*idle_l[4];
	void	*idle_r[4];
	void	*walk_r[4];
	void	*walk_l[4];

	int		delay_between_frames;
	int		frame_count;
	int		current_frame;
	int		frame_delay;
	int		delay_counter;
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
	int			is_moving;
	void		*life_sprite;
	char		last_direction;
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
	t_animation	anim;
}	t_game;

//animation
int			idle_right_loop(t_game *game);
int			idle_left_loop(t_game *game);
int 		walk_left_loop(t_game *game);
int 		walk_right_loop(t_game *game);
//load images
void		load_idle_right(t_game *game);
void		load_idle_left(t_game *game);
void		load_walk_left(t_game *game);
void		load_walk_right(t_game *game);
void		load_images(t_game *game);
//game
void		load_game(t_game *game);
int 		setup_game(t_game *game);
int			exit_game(t_game *game);
int			initialize_game(t_game *game, char **av);
//input
int			input(int command, t_game *game);
int 		control(int keycode, t_game *game);
//player
void 		update_player_animation(t_game *game);
int			is_player_moving(t_game *game);
//player_mouvement
void		move_player(t_game *game, int x, int y);
//mouvement
void 		move_player(t_game *game, int x, int y);
int			move_vertical(t_game *game, int direction);
int			move_horizontal(t_game *game, int direction);
int			move_to_tile(t_game *game, int x, int y);
int			can_move_to_tile(t_game *game, int x, int y);
//graphics
void		place_graphics(t_game *game, void *image, int height, int width);
int 		add_graphics(t_game *game, int height, int width);
//read map
void		process_map(t_game *game);
int			read_map(t_game *game, char *file);
//tools
void		count_collectables(t_game *game);
void		update_camera(t_game *game);
void		handle_camera(t_game *game, int move_success);
void		find_player(t_game *game);

#endif
