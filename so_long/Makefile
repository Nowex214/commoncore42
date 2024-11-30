SHELL = /bin/sh

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(MINILIBX_DIR) -I$(LIBFT_DIR)
MINIFLAGS = -L$(MINILIBX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -lm -lbsd
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

SRCS = srcs/core_game/error.c \
		srcs/core_game/main.c \
		srcs/read_map/display_file.c \
		srcs/read_map/read_map.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINIFLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re