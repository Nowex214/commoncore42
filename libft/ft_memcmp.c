/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:59:34 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/06 21:59:34 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int memcmp(const void *pt1, const void *pt2, size_t len)
{
    size_t i;

    i = 0;
    while (i < len && *(unsigned char *)(pt1 + i) == *(unsigned char *)(pt2 + i))
        i++;
    if (i < len)
        return (*(unsigned char *)(pt1 + i) - *(unsigned char *)(pt2 + i));
    return (0);
}

int main(void)
{
    const char b1[] = "Hello, world!";
    const char b2[] = "Hello, there!";
    size_t len = 5;
    int res;

    res = memcmp(b1, b2, len);

    if (res == 0)
        printf("Les %zu premiers octets des deux blocks sont identiques.\n", len);
    else if (res < 0)
        printf("le premier bloc est inférieur au deuxième dans les %zu premiers octets.\n", len);
    else
        printf("Le premier bloc est supérieur au deuxième dans les %zu premiers octets.\n", len);
    return (0);
}