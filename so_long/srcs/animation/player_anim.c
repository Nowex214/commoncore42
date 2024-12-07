/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:31:04 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/07 14:39:25 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void update_animation(t_animation *anim, int fps)
{
	if (!anim || !anim->frames)
		return ;
	anim->delay_counter += fps;
	if (anim->delay_counter >= anim->frame_delay)
	{
		anim->delay_counter = 0;
		if (anim->frames->next)
			anim->frames = anim->frames->next;
		else
			anim->frames = anim->start;
		ft_putchar_fd('\n', 1);
	}
}

int update_player_animation(void *param)
{
	t_game		*game;
	t_animation	*anim;

	game = (t_game *)param;
	if (game->input.left)
	{
		game->player.last_direction = 'L';
		anim = &game->player.idle_left;
		update_animation(anim, 1);
	}
	else if (game->input.right)
	{
		game->player.last_direction = 'R';
		anim = &game->player.idle_right;
		update_animation(anim, 1);
	}
	return (0);
}
