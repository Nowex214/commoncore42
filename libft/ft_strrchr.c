/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:51:20 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/06 20:51:20 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *strrchr(const char *str, int i)
{
    int j;
    char    *c;

    j = 0;
    c = NULL;
    while (str[j])
    {
        if (str[j] == (char)i)
            c = ((char *)&str[j]);
        j++;
    }
    if (str[j] == (char)i)
        return ((char *)&str[j]);
    return (c);
}
/*
int main(void)
{
    const char str[] = "Hello, world!";
    char ch = 'o';
    char *res;

    res = strrchr(str,ch);
    if (res != NULL)
        printf ("Dernière occurence de '%c' trouvée à la position: %ld\n", ch, res - str);
    else
        printf ("Le caractère '%c' n'a pas été trouvé.\n", ch);
    return (0);
}
*/