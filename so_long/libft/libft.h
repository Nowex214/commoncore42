/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:06:19 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/21 15:37:47 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

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
char				*ft_strdup(char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*get_next_line(int fd);
char				*ft_strchr(const char *str, int i);

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
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_send_bytes(int pid, char *bytes, size_t len);

int					ft_atoi(const char *str);
int					ft_toupper(int i);
int					ft_tolower(int i);
int					ft_strlen(const char *str);
int					ft_strlen_gnl(char *str);
int					ft_isprint(int i);
int					ft_isdigit(int i);
int					ft_isascii(int i);
int					ft_isalpha(int i);
int					ft_isalnum(int i);
int					ft_memcmp(const void *pt1, const void *pt2, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_strlcat(char *dest, char *src, size_t size);
int					ft_putchar(char c);
int					ft_putunbr(va_list args);
int					ft_putnbr(va_list args);
int					ft_putpointer(void *ptr);
int					ft_puthex(size_t nbr, char format);
int					ft_printf(const char *format, ...);
int					ft_putstr(va_list args);
int					ft_lstsize(t_list *lst);

size_t				ft_strlcpy(char *dest, const char *src, size_t size);

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif