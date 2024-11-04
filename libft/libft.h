/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:06:19 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/04 09:47:44 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *str, int i);
char				*ft_strchr(const char *str, int i);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(char *src);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(const char *str, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				*ft_memchr(const void *memB, int chrC, size_t len);
void				*ft_bzero(void *ptr, size_t len);
void				*ft_memset(void *ptr, int value, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

int					ft_atoi(const char *str);
int					ft_toupper(int i);
int					ft_tolower(int i);
int					ft_strlen(const char *str);
int					ft_isprint(int i);
int					ft_isdigit(int i);
int					ft_isascii(int i);
int					ft_isalpha(int i);
int					ft_isalnum(int i);
int					ft_memcmp(const void *pt1, const void *pt2, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_strlcat(char *dest, char *src, size_t size);

size_t				ft_strlcpy(char *dest, const char *src, size_t size);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *));

int					ft_lstsize(t_list *lst);

#endif
