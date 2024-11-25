/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:37:42 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/24 18:37:42 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	static size_t	bit_count = 0;
	static char		received_bytes = 0;

	if (signum == SIGUSR1)
		received_bytes &= ~(1 << bit_count);
	if (signum == SIGUSR2)
		received_bytes |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (received_bytes == '\n')
		{
			kill(info->si_pid, SIGUSR1);
		}
		ft_printf("%c", received_bytes);
		received_bytes = 0;
		bit_count = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	struct sigaction sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./server_bonus\n");
		return (1);
	}
	pid = getpid();

	ft_printf("Server PID: %d\n", pid);
	ft_printf("Waiting for messages...\n");
	sa.sa_sigaction = ft_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
