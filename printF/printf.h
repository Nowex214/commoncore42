/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:06:37 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/17 17:06:37 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_putchar(char c);
int		ft_putunbr(unsigned int nb);
int		ft_putnbr(int nb);
int		ft_putpointer(void *ptr);
int		ft_puthex(size_t nbr, char format);
int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);

char	*ft_strchr(const char *str, int i);

#endif