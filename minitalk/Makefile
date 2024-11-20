CLIENT = client
SERVER = server
CC = cc
PRINTF = printF
CFLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers
LDFLAGS = -L$(PRINTF) -lftprintf

all:
	@make -s -C $(PRINTF)
	@$(CC) $(CFLAGS) server.c -o $(SERVER) $(LDFLAGS)
	@$(CC) $(CFLAGS) client.c -o $(CLIENT) $(LDFLAGS)
	@echo "Server and Client compiled"

clean:
	@make clean -s -C $(PRINTF)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client removed"

re: fclean all

.PHONY: all clean fclean re