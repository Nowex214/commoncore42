/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:04:47 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/19 20:53:45 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static void	ft_signal_handler(int signum)
{
	static size_t	bit_count;
	static char	received_bytes;

	bit_count = 0;
	if (signum == SIGUSR1)
		received_bytes &= ~(1 << bit_count);
	if (signum == SIGUSR2)
		received_bytes |= ~(1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf(&received_bytes);
		received_bytes = 0;
		bit_count = 0;
	}
}

