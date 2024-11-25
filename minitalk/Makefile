SHELL = /bin/sh

SERVER_SRCS = srcs/server.c
CLIENT_SRCS = srcs/client.c
CLIENT_BONUS_SRCS = srcs/client_bonus.c
SERVER_BONUS_SRCS = srcs/server_bonus.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR)
AR = ar rcs
ECHO = echo
CURRENT = 0

DEF_COLOR	=	\033[0m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
WHITE		=	\033[0;97m
PURPLE		=	\033[0;95m

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

TOTAL_OBJS = $(shell echo $$(($(words $(SERVER_OBJS)) + $(words $(CLIENT_OBJS)))))

all: $(LIBFT) server client
bonus: $(LIBFT) server_bonus client_bonus

$(LIBFT):
	@$(ECHO) "$(PURPLE)Entering directory: $(LIBFT_DIR)$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

server: $(SERVER_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft || { $(ECHO) "$(RED)Error: Server compilation failed!$(DEF_COLOR)"; exit 1; }
	@$(ECHO) "$(WHITE) server.c > $(DEF_COLOR) $(GREEN)completed! $(DEF_COLOR)"

client: $(CLIENT_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft || { $(ECHO) "$(RED)Error: Client compilation failed!$(DEF_COLOR)"; exit 1; }
	@$(ECHO) "$(WHITE) client.c > $(DEF_COLOR) $(GREEN)completed! $(DEF_COLOR)"

server_bonus: $(SERVER_BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft || { $(ECHO) "$(RED)Error: Server bonus compilation failed!$(DEF_COLOR)"; exit 1; }
	@$(ECHO) "$(WHITE) server_bonus.c > $(DEF_COLOR) $(GREEN)completed! $(DEF_COLOR)"

client_bonus: $(CLIENT_BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft || { $(ECHO) "$(RED)Error: Client bonus compilation failed!$(DEF_COLOR)"; exit 1; }
	@$(ECHO) "$(WHITE) client_bonus.c > $(DEF_COLOR) $(GREEN)completed! $(DEF_COLOR)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f server client server_bonus client_bonus
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(ECHO) "$(BLUE)Full clean completed!$(DEF_COLOR)"

re: fclean all

.PHONY: all bonus clean fclean re