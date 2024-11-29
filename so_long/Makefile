#Fonction
SHELL = /bin/bash
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0 -I$(MINILIBX_DIR) -I$(LIBFT_DIR)
AR = ar rcs
ECHO = echo
CURRENT = 0

#Library
MINILIBX_DIR = minilibx-linux
LIBFT_DIR = libft
SRCS_DIR = srcs
OBJS_DIR = objs
MINILIBX = $(MINILIBX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a

#Flags de liaison
LIBS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft

#Colors
DEF_COLOR	=	\x1b[0m
ORANGE		=	\x1b[0;33m
GRAY		=	\x1b[0;90m
RED			=	\x1b[0;91m
GREEN		=	\x1b[1;92m
YELLOW		=	\x1b[1;93m
BLUE		=	\x1b[0;94m
MAGENTA		=	\x1b[0;95m
CYAN		=	\x1b[0;96m
WHITE		=	\x1b[0;97m

#files
SRCS = $(addprefix $(SRCS_DIR)/, read_map/display_file.c\
								read_map/read_map.c\
								core_game/error.c)

#Objects
OBJS_SRCS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
TOTAL_OBJS = $(shell echo $$(($(words $(OBJS_SRCS)))))

#Compilation
all: $(NAME) $(LIBFT) $(MINILIBX)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -s -C $(MINILIBX_DIR) X11_INCLUDE=/usr/include/X11 X11_LIB=/usr/lib

$(NAME): $(OBJS_SRCS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_SRCS) $(LIBFT) $(MINILIBX) $(LIBS)
	@printf "\r\x1b[K$(WHITE)Progress: [%d/%d] 100%% > $(DEF_COLOR) $(GREEN)Compilation completed$(DEF_COLOR)\n" $(TOTAL_OBJS) $(TOTAL_OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

#Clean
clean:
	rm -rf $(OBJS_DIR)
	-$(MAKE) -C $(LIBFT_DIR) clean
	-$(MAKE) -C $(MINILIBX_DIR) clean

#Fully clean
fclean: clean
	@rm -f $(NAME)
	-@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus