#Fonction
SHELL = /bin/bash
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
ECHO = echo
CURRENT = 0

#Library
MINILIBX_DIR = minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
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
GAME_RULES = game_rules/ft_controls.c\
			game_rules/ft_display.c\
			game_rules/ft_maps.c\
			game_rules/so_long.c

#Objects
OBJS_GAME_RULES = $(GAME_RULES:.c=.o)

TOTAL_OBJS = $(shell echo $$(($(words $(OBJS_GAME_RULES)))))


#Compilation
all: $(NAME) $(LIBFT) $(MINILIBX)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR) X11_INCLUDE=/usr/include/X11 X11_LIB=/usr/lib

$(NAME): $(OBJS_GAME_RULES) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_GAME_RULES) $(LIBFT) $(MINILIBX)
	@printf "\r\x1b[K$(WHITE)Progress: [%d/%d] 100%% > $(DEF_COLOR) $(GREEN)Compilation completed$(DEF_COLOR)\n" $(TOTAL_OBJS) $(TOTAL_OBJS)

%.o: %.c
	$(eval CURRENT := $(shell echo $$(($(CURRENT)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@ || { $(ECHO) "$(RED)Error: Compilation failed for $<!$(DEF_COLOR)"; exit 1; }
	@printf "\r$(WHITE)Progress: [%d/%d] %d%% $(DEF_COLOR) > $(YELLOW)Compiling: %s$(DEF_COLOR)" $(CURRENT) $(TOTAL_OBJS) $$(($(CURRENT)*100/$(TOTAL_OBJS))) $<
	@sleep 0.00001

clean:
	@rm -f $(OBJS_GAME_RULES)
	@$(ECHO) "$(BLUE)Cleaning completed!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME) $(TOTAL_OBJS)

re: fclean all

.PHONY: all clean fclean re bonus