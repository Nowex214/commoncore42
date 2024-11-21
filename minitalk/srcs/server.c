/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:04:47 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/21 19:55:18 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_signal_handler(int signum)
{
	static size_t	bit_count;
	static char		received_bytes;

	bit_count = 0;
	if (signum == SIGUSR1)
		received_bytes &= ~(1 << bit_count);
	if (signum == SIGUSR2)
		received_bytes |= ~(1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", received_bytes);
		received_bytes = 0;
		bit_count = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	(void)av;

	if (ac != 1)
	{	
		write(1, "Error: wrong format.\n", 21);
		write(1, "Try: ./server\n", 14);
		ft_printf("Error: wrong format");
		ft_printf("Try: ./server");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Waiting for messages...\n");
	while (1)
	{
		signal(SIGUSR1, ft_signal_handler);
		signal(SIGUSR2, ft_signal_handler);
		pause();
	}
	return (0);
}
