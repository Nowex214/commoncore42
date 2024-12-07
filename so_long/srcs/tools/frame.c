/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:44:58 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/07 11:01:24 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int calculate_fps(void *param)
{
	static int frame_count = 0;
	static long last_time = 0;
	long current_time;
	double elapsed_time;
	static double fps;

	t_game *game = (t_game *)param;
	(void)game;
	if (last_time == 0)
	{
		frame_count = 0;
		last_time = get_time_in_ms();
		fps = 0;
	}
	current_time = get_time_in_ms();
	elapsed_time = current_time - last_time;
	frame_count++;
	if (elapsed_time >= 1.0)
	{
		fps = frame_count / elapsed_time;
		frame_count = 0;
		last_time = current_time;
		game->fps = (int)fps;
		//printf("FPS: %.2f\n", fps);
	}
	return (0);
}
