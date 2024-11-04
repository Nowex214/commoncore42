CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
LIBFT = ft_atoi.c\
    ft_bzero.c\
    ft_isalnum.c\
    ft_isalpha.c\
    ft_isascii.c\
    ft_isdigit.c\
    ft_isprint.c\
    ft_memchr.c\
    ft_memcmp.c\
    ft_memcpy.c\
    ft_memmove.c\
    ft_memset.c\
    ft_strchr.c\
    ft_strlcat.c\
    ft_strlcpy.c\
    ft_strncmp.c\
    ft_strnstr.c\
    ft_strrchr.c\
    ft_tolower.c\
    ft_toupper.c\
    ft_strdup.c\
    ft_substr.c\
    ft_strlen.c\
    ft_calloc.c\
    ft_strjoin.c\
    ft_strtrim.c\
    ft_split.c\
    ft_itoa.c\
    ft_strmapi.c\
    ft_striteri.c\
    ft_putchar_fd.c\
    ft_putendl_fd.c\
    ft_putnbr_fd.c\
    ft_putstr_fd.c

LIBFT_BONUS =   ft_lstsize_bonus.c \
                ft_lstlast_bonus.c\
                ft_lstadd_back_bonus.c\
                ft_lstdelone_bonus.c\
                ft_lstclear_bonus.c\
                ft_lstiter_bonus.c\
                ft_lstmap_bonus.c\
                ft_lstnew_bonus.c\
                ft_lstadd_front_bonus.c

OBJS = $(LIBFT:.c=.o)
OBJS_BONUS = $(LIBFT_BONUS:.c=.o)

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
