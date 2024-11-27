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
MINILIBX = $(MINILIBX_DIR)/libmlx.a
LIBFT_DIR = libft
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
SRCS = srcs/ft_controls.c\
            srcs/ft_display.c\
            srcs/ft_maps.c\
			srcs/so_long.c\
			srcs/ft_handling_error.c

#Objects
OBJS_SRCS = $(SRCS:.c=.o)

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

%.o: %.c
	$(eval CURRENT := $(shell echo $$(($(CURRENT)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@ || { $(ECHO) "$(RED)Error: Compilation failed for $<!$(DEF_COLOR)"; exit 1; }
	@printf "\r$(WHITE)Progress: [%d/%d] %d%% $(DEF_COLOR) > $(YELLOW)Compiling: %s$(DEF_COLOR)" $(CURRENT) $(TOTAL_OBJS) $$(($(CURRENT)*100/$(TOTAL_OBJS))) $<
	@sleep 0.00001

# Clean target
clean:
	@rm -f $(OBJS) $(OBJS_SRCS)
	@$(MAKE) -s -C $(MINILIBX_DIR) clean
	@$(MAKE) -s -C $(LIBFT_DIR) clean

# Fully clean target
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus