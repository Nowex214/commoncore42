/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:36:54 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/30 10:48:03 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	total_size;

	if (count != 0 && size > (size_t) - 1 / count)
		return (NULL);
	total_size = count * size;
	dest = (char *)malloc(total_size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, total_size);
	return (dest);
}
