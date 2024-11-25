/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:33:19 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/24 18:33:19 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static void	ft_reception(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received!\n");
}

void	ft_send_bytes(int pid, char *bytes, size_t len)
{
	size_t	i;
	int	bit_index;

	i = 0;
	while (i < len)
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			if ((bytes[i] >> bit_index) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit_index++;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Try: ./client_bonus <PID> <message>\n");
		return (1);
	}
	else
	{
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, ft_reception);
		while (av[2][i])
		{
			ft_send_bytes(pid, &av[2][i], 1);
			i++;
		}
		ft_send_bytes(pid, "\n", 1);
	}
	return (0);
}
