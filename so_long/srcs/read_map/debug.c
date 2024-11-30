/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:13:41 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/28 12:13:41 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_debug_option(int ac, char **av)
{
    if (ac == 3 && av[2] && (ft_strcmp(av[2], "DEBUG=1") == 0
        || ft_strcmp(av[2], "DEBUG=2") == 0))
        return (1);
    if (ac != 2)
        return (1);
    return (0);
}
