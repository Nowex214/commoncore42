/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:51:37 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/21 20:14:40 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		write(1, "Error: wrong format.\n", 21);
		write(1, "Try: ./client <PID> <message>\n", 30);
		ft_printf("Error: wrong format.\n");
		ft_printf("Try: ./client <PID> <message>");
		return (1);
	}
	else
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			ft_send_bytes(pid, &av[2][i], 1);
			i++;
		}
		ft_send_bytes(pid, '\n', 1);
	}
	return (0);
}
