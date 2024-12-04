/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:16:41 by ehenry            #+#    #+#             */
/*   Updated: 2024/12/04 22:20:40 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/so_long.h"

t_list	*load_animation_frames(void *mlx, char *base_path, int frame_count)
{
	t_list	*frames;
	t_list	*new_frame;
	void	*image;
	char	frame_path[60];
	int		i;
	int		width;
	int		height;

	frames = NULL;
	i = 0;
	while (i < frame_count)
	{
		snprintf(frame_path, sizeof(frame_path), "%s%d.xpm", base_path, i + 1);
		ft_putstr_fd("Loading frame: ", 1);
		ft_putstr_fd(frame_path, 1);
		ft_putchar_fd('\n', 1);
		image = mlx_xpm_file_to_image(mlx, frame_path, &width, &height);
		if (!image)
		{
			ft_putstr_fd("Error: Failed to load frame: ", 2);
			ft_putstr_fd(frame_path, 2);
			ft_putchar_fd('\n', 2);
			ft_lstclear(&frames, free);
			return (NULL);
		}
		new_frame = ft_lstnew(image);
		if (!new_frame)
		{
			ft_lstclear(&frames, free);
			return (NULL);
		}
		ft_lstadd_back(&frames, new_frame);
		i++;
	}
	return (frames);
}

void update_animation(t_animation *anim, int fps)
{
	anim->delay_counter += fps;
	if (anim->delay_counter >= anim->frame_delay)
	{
		anim->delay_counter = 0;
		if (anim->frames && anim->frames->next)
			anim->frames = anim->frames->next;
		else if (anim->frames)
			anim->frames = anim->start;
	}
}


void free_animation(t_game *game, t_list *start)
{
	t_list *temp;

	while (start)
	{
		temp = start;
		start = start->next;
		if (game && temp->content)
			mlx_destroy_image(game->mlx, temp->content);
		free(temp);
	}
}

