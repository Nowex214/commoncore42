/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:04:50 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/19 20:56:01 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_send_bytes(int pid, char *bytes, size_t len)
{
	size_t	i;
	size_t	bit_index;

	i = 0;
	bit_index = 7;
	while (i < len)
	{
		while (bit_index >= 0)
		{
			if ((bytes[i] >> bit_index) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit_index--;
			usleep(100);
		}
		i++;
	}
}

