/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:51:37 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/20 16:29:42 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printF/ft_printf.h"
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
			usleep(10000);
		}
		i++;
	}
}
