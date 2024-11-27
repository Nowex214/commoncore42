/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:18:52 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/27 15:23:31 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(const char *msg)
{
	if (msg)
	{
		write(2, "Error: ", 7);
		while (*msg)
		{
			write(2, msg, 1);
			msg++;
		}
		write(2, "\n", 1);
	}
	return (0);
}
