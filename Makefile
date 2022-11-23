# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 10:48:12 by eukwon            #+#    #+#              #
#    Updated: 2022/11/19 19:40:23 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAG = -Wall -Wextra -g -fsanitize=address -g
# -Werror

AR = ar
ARFLAG = -crs

RM = rm
RMFLAG = -rf

INCLUDES_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

# ft_printf
FT_PRINTF = libftprintf.a
FT_PRINTF_DIR = ./lib/ft_printf
FT_PRINTF_FILE = $(FT_PRINTF_DIR)/$(FT_PRINTF)
FT_PRINTF_FLAGS = -L $(FT_PRINTF_DIR) -lftprintf
FT_PRINTF_INC_DIR = $(FT_PRINTF_DIR)/includes
FT_PRINTF_INC = ${FT_PRINTF_INC_DIR}/ft_printf.h

# libft
LIBFT = libft.a
LIBFT_DIR = ./lib/ft_printf/lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft
LIBFT_INC_DIR = $(LIBFT_DIR)/includes
LIBFT_INC = $(LIBFT_INC_DIR)/libft.h

# libmlx
LIBMLX = libmlx.a
LIBMLX_DIR = ./lib/minilibx
LIBMLX_FILE = $(LIBMLX_DIR)/$(LIBMLX)
LIBMLX_FLAGS = -L $(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBMLX_INC = ./lib/minilibx/mlx.h

# color
NO_COLOR = \e[0m
LIGHT_GREEN = \e[1;32;189;147;249m
GREEN = \e[0;32;189;147;249m
LIGHT_GRAY = \e[1;32;255;121;198
LF = \e[1K\r$(NO_COLOR)
CRLF = \n$(LF)

SRCS = $(addprefix $(SRCS_DIR)/, \
	main.c\
	check_params.c\
	map_parsing.c\
	get_next_line.c\
)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./lib/ft_printf all
	$(MAKE) -C ./lib/minilibx all
	@printf "$(LF)$(LIGHT_GREEN)Successfully Created $(GREEN)$(NAME)'s Object files!"
	@printf "$(CRLF)$(LIGHT_GREEN)Archiving! $(GREEN)$@${CRLF}"
	$(CC) $(CFLAG) $(OBJS) $(LIBMLX_DIR)/$(LIBMLX) $(FT_PRINTF_DIR)/$(FT_PRINTF) -I $(INCLUDES_DIR) $(LIBMLX_FLAGS) $(FT_PRINTF_FLAGS) $(LIBFT_FLAGS) -o $(NAME)
	@printf "$(LF)$(LIGHT_GREEN)Successfully Archived $(GREEN)$@$(LIGHT_GREEN)!${CRLF}"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAG) -c $^ -o $@ -I $(INCLUDES_DIR) -I $(LIBMLX_INC) -I $(FT_PRINTF_INC) -I $(LIBFT_INC)
	@printf "$(LF)$(LIGHT_GREEN)Create $(GREEN)$@ $(LIGHT_GREEN)from $(GREEN)$<${CRLF}"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean :
	@$(MAKE) -C ./lib/ft_printf clean
	@$(MAKE) -C ./lib/minilibx clean
	@${RM} $(RMFLAG) $(OBJS) $(OBJS_DIR)
	@printf "$(LF)$(LIGHT_GREEN)Cleaning $(GREEN)$(NAME)'s Object files...${CRLF}"

fclean : clean
	@${RM} $(RMFLAG) $(NAME)
	@printf "$(LF)$(LIGHT_GREEN)Cleaning $(GREEN)$(NAME)${CRLF}"

re : fclean all

.PHONY : all clean fclean re