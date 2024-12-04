/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:31:04 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/04 21:31:46 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/so_long.h"

void render_player_animation(t_game *game)
{
	t_animation *anim;

	anim = &game->player.idle_anim;
	if (anim->frames && anim->frames->content)
	{
		mlx_put_image_to_window(game->mlx, game->win, anim->frames->content,
			game->player.player_x * SPRITE_SIZE - game->cam.cam_x, 
			game->player.player_y * SPRITE_SIZE - game->cam.cam_y);
	}
}
int update_player_animation(void *param)
{
	t_game *game = (t_game *)param;
	t_animation *anim = &game->player.idle_anim;

	if (game->input.up == 0 && game->input.down == 0 && game->input.left == 0 && game->input.right == 0)
	{
		if (!anim->frames)
		{
			if (game->player.last_direction == 'L' && !anim->frames)
				anim->frames = load_animation_frames(game, "./sprite/player/idle_l/", 10);
			else if (game->player.last_direction == 'R' && !anim->frames)
				anim->frames = load_animation_frames(game, "./sprite/player/idle_r/", 10);
			
			anim->frame_count = 10;
			anim->frame_delay = 6;
			anim->delay_counter = 0;
		}
		update_animation(anim, game->fps);
	}
	return 0;
}
