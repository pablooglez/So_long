# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 14:38:21 by pablogon          #+#    #+#              #
#    Updated: 2024/08/31 23:37:52 by pablogon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= so_long

CFLAGS:= -g -Wall -Werror -Wextra \
		-g -fsanitize=address,undefined \
		#-Wunreachable-code -Ofast \


MLX_DIR = ./MLX42/build
MLX		= $(MLX_DIR)/libmlx42.a
LINK	= -ldl -lglfw -lpthread -lm

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS := -I$(LIBFT) -I$(MLX)

SRCS	:= src/check.c \
src/create_game.c \
src/error.c \
src/flood_fill.c \
src/get_next_line_bonus.c \
src/get_next_line_utils_bonus.c \
src/main.c \
src/map.c \
src/moves.c \
src/utils.c \


OBJS	:= ${SRCS:.c=.o}

all: mlx42 libft $(NAME)
libft:
	@make -C $(LIBFT_DIR)
mlx42:
	@make -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(HEADERS) $(LINK) -o $(NAME)
	@echo "Compiling So_long..."

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re, libft, mlx42