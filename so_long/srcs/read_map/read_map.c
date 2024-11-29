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

int	chek_debug_option(int ac, char **av)
{
	if (ac == 3 && av[2] && (ft_strcmp(av[2], "DEBUG=1") == 0 
		|| ft_strcmp(av[2], "DEBUG=2") == 0))
		return (1);
	if (ac != 2)
		return (1);
	return (0);
}

int	verification(t_game *game, char *file_path)
{
    int	len;

    len = ft_strlen(file_path);
    if (len < 4)
        return (0);
    if (strcmp(&file_path[len - 4], ".ber") != 0)
        return (0);
    game->map_fd = open(file_path, O_RDONLY);
    if (game->map_fd < 0)
        return (0);
    return (1);
}

int	count_map_lines(t_game *game, char *file_path)
{
    char	*line;
    int		height;

    height = 0;
    game->fd = open(file_path, O_RDONLY);
    if (game->fd < 0)
        return (error("Error: cannot open the map file"));
    while ((line = get_next_line(game->fd)) != NULL)
    {
        height++;
        free(line);
    }
    if (height == 0)
        return (error("Error: map file is empty"));
    game->map = ft_calloc(height + 1, sizeof(char *));
    return (height);
}

int	read_map(t_game *game, char *file_path)
{
    char	*line;

    game->fd = open(file_path, O_RDONLY);
    if (game->fd < 0)
        return (error("Error: cannot open the map file"));
    line = get_next_line(game->fd);
    if (!line)
        return (error("Error: map file is empty"));
    game->widthmap = ft_strlen(line);
    free(line);
    return (1);
}

int	map_check(t_game *game)
{
    char	*line;
    size_t	i;

    i = 0;
    while ((line = get_next_line(game->fd)) != NULL)
    {
        if ((size_t)ft_strlen(line) != game->widthmap)
            return (error("Error: map width is inconsistent"));
        if (i == 0 || i == game->heightmap - 1)
        {
            if (line[0] != '1' || line[game->widthmap - 1] != '1')
                return (error("Error: map is not enclosed by walls"));
        }
        free(line);
        i++;
    }
    return (1);
}
