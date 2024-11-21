SHELL = /bin/sh

SERVER_SRCS = srcs/server.c
CLIENT_SRCS = srcs/client.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
ECHO = echo -e
CURRENT = 0

DEF_COLOR	=	\033[0m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
WHITE		=	\033[0;97m

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
TOTAL_OBJS = $(shell echo $$(($(words $(SERVER_OBJS)) + $(words $(CLIENT_OBJS)))))

all: server client

server: $(SERVER_OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ || { $(ECHO) "$(RED)Error: Server compilation failed!$(DEF_COLOR)"; exit 1; }
	@$(ECHO) "$(GREEN)Server compilation completed!$(DEF_COLOR)"

client: $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ || { $(ECHO) "$(RED)Error: Client compilation failed!$(DEF_COLOR)"; exit 1; }
	@$(ECHO) "$(GREEN)Client compilation completed!$(DEF_COLOR)"

%.o: %.c
	$(eval CURRENT := $(shell echo $$(($(CURRENT)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@ || { $(ECHO) "$(RED)Error: Compilation failed for $<!$(DEF_COLOR)"; exit 1; }
	@printf "\r$(WHITE)Progress: [%d/%d] %d%% $(DEF_COLOR) > $(YELLOW)Compiling: %s$(DEF_COLOR)" $(CURRENT) $(TOTAL_OBJS) $$(($(CURRENT)*100/$(TOTAL_OBJS))) $<
	@sleep 0.00001
	@printf "\033[K" # Efface la ligne précédente après la compilation

clean:
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	@$(ECHO) "$(BLUE)Cleaning completed!$(DEF_COLOR)"

fclean: clean
	@rm -f server client
	@$(ECHO) "$(BLUE)Full clean completed!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
