/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student42.luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:06:19 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/09 19:10:18 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

char *ft_strnstr(const char *s1, const char *s2, size_t len)
char *ft_strrchr(const char *str, int i)
char *ft_strchr(const char *str, int i)
char *ft_strlcpy(char *dest, char *src)
char *ft_strdup(char *src)

void *ft_memchr(const void *memB, int chrC, size_t len)
void *ft_bzero(void *ptr, size_t len)
void *ft_memset(void *ptr, int value, size_t len)
void *ft_memmove(void *dest, const void *src, size_t len)
void *ft_memcpy(void *dest, const void *src, size_t len)

int ft_atoi(char *str)
int ft_toupper(int i)
int ft_tolower(int i)
int ft_strlen(char *str)
int ft_isprint(int i)
int ft_isdigit(int i)
int ft_isascii(int i)
int ft_isalpha(int i)
int ft_isalnum(int i)
int memcmp(const void *pt1, const void *pt2, size_t len)
int strncmp(const char *s1, const char *s2, size_t len)
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)

#endif
