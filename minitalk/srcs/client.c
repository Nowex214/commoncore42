/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logname <logname@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:13:18 by logname           #+#    #+#             */
/*   Updated: 2024/11/25 00:49:30 by logname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:51:37 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/25 00:49:19 by ehenry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_send_bytes(int pid, const char *bytes, size_t len)
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
		ft_printf("Try: ./client <PID> <message>\n");
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
		ft_send_bytes(pid, "\n", 1);
	}
	return (0);
}
