SHELL = /bin/bash
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar rcs
ECHO = echo -e
CURRENT = 0

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
	ft_strcmp.c\
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

PRINTF = ft_printf.c\
		ft_putchar_printf.c\
		ft_puthex_printf.c\
		ft_putnbr_printf.c\
		ft_putpointer_printf.c\
		ft_putstr_printf.c\
		ft_putunbr_printf.c\

GNL = get_next_line_bonus.c\
		get_next_line_utils_bonus.c\

DEF_COLOR	=	\033[0m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

OBJS = $(LIBFT:.c=.o)
OBJS_BONUS = $(LIBFT_BONUS:.c=.o)
OBJS_PRINTF = $(PRINTF:.c=.o)
OBJS_GNL = $(GNL:.c=.o)

TOTAL_OBJS = $(shell echo $$(($(words $(OBJS)) + $(words $(OBJS_BONUS)) + $(words $(OBJS_PRINTF)) + $(words $(OBJS_GNL)))))

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL) $(OBJS_BONUS)
	@$(AR) $(NAME) $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL) $(OBJS_BONUS) || { $(ECHO) "$(RED)Error: Compilation failed!$(DEF_COLOR)"; exit 1; }
	@printf "\r\033[K$(WHITE)Progress: [%d/%d] 100%% > $(DEF_COLOR) $(GREEN)Compilation completed$(DEF_COLOR)\n" $(TOTAL_OBJS) $(TOTAL_OBJS)

%.o: %.c
	$(eval CURRENT := $(shell echo $$(($(CURRENT)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@ || { $(ECHO) "$(RED)Error: Compilation failed for $<!$(DEF_COLOR)"; exit 1; }
	@printf "\r\033[K$(WHITE)Progress: [%d/%d] %d%% $(DEF_COLOR) > $(YELLOW)Compiling: %s$(DEF_COLOR)" $(CURRENT) $(TOTAL_OBJS) $$(($(CURRENT)*100/$(TOTAL_OBJS))) $<
	@sleep 0.00001

clean:
	@rm -f $(OBJS) $(OBJS_BONUS) $(OBJS_PRINTF) $(OBJS_GNL)
	@$(ECHO) "$(BLUE)Cleaning completed!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
