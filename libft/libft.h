/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:06:19 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/29 13:26:05 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strrchr(const char *str, int i);
char	*ft_strchr(const char *str, int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *str, char c);
char	*ft_itao(int n);
void	*ft_memchr(const void *memB, int chrC, size_t len);
void	*ft_bzero(void *ptr, size_t len);
void	*ft_memset(void *ptr, int value, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);

int		ft_atoi(char *str);
int		ft_toupper(int i);
int		ft_tolower(int i);
int		ft_strlen(const char *str);
int		ft_isprint(int i);
int		ft_isdigit(int i);
int		ft_isascii(int i);
int		ft_isalpha(int i);
int		ft_isalnum(int i);
int		ft_memcmp(const void *pt1, const void *pt2, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_strlcat(char *dest, char *src, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
#endif
