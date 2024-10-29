/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:36:54 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/22 12:00:49 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;
	size_t	total_size;

	total_size = count * size;
	dest = (char *)malloc(total_size);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, count * size);
	return (dest);
}
