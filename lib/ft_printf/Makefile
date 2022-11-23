# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 15:32:00 by eukwon            #+#    #+#              #
#    Updated: 2022/11/23 17:33:55 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = AR
ARFLAG = -crs

RM = rm
RMFLAG = -rf

INCLUDES_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NAME))

# libft
LIBFT = libft.a
LIBFT_DIR = ./lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft
LIBFT_INC_DIR = $(LIBFT_DIR)/includes

# color
NO_COLOR = \e[0m
LIGHT_GREEN = \e[1;32;189;147;249m
GREEN = \e[0;32;189;147;249m
LIGHT_GRAY = \e[1;32;255;121;198
LF = \e[1K\r$(NO_COLOR)
CRLF = \n$(LF)

SRCS_NAME = \
	ft_isdigit.c \
	ft_itoa.c \
	ft_printf.c \
	ft_putchar_pf.c \
	ft_putnbr_base.c \
	ft_putstr_pf.c \
	ft_strdup.c \
	ft_strdup_without_newline.c\
	ft_strjoin_without_newline.c\
	ft_strlen.c

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./lib/libft all
	${AR} ${ARFLAGS} $(NAME) $(OBJS)
	@printf "$(LF)$(LIGHT_GREEN)Successfully Archived! $(GREEN)$@$(LIGHT_GREEN)${CRLF}"

libft :
	$(MAKE) -C ./lib/libft all
	@printf "$(CRLF)$(LIGHT_GREEN)Archiving! $(GREEN)$@${CRLF}"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCLUDES_DIR)
	@printf "$(LF)$(LIGHT_GREEN)Create $(GREEN)$@ $(LIGHT_GREEN)from $(GREEN)$<${CRLF}"

clean :
	@$(MAKE) -C ./lib/libft clean
	$(RM) $(RMFLAG) $(OBJS_DIR) $(NAME)
	@printf "$(LF)$(LIGHT_GREEN)Cleaning $(GREEN)$(NAME)'s Object files...${CRLF}"


fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

.PHONY: all clean fclean re