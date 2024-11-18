/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:06:37 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/18 12:04:21 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putunbr(va_list args);
int 	ft_putnbr(va_list args);
int		ft_putpointer(void *ptr);
int		ft_puthex(size_t nbr, char format);
int		ft_printf(const char *format, ...);
int		ft_putstr(va_list args);

#endif