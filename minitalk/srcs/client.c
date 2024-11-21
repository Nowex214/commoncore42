/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:51:37 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/21 15:41:51 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <sys/types.h>
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

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;
	(void)av;

	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	ft_send_bytes(pid, message, ft_strlen(message));
	return (0);
}
