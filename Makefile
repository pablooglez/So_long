# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 14:38:21 by pablogon          #+#    #+#              #
#    Updated: 2024/08/24 18:15:32 by pablogon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= so_long

CFLAGS:= -g -Wall -Werror -Wextra 

LIBFT_DIR = ./Libft

LIBFT = $(LIBFT_DIR)/libft.a

HEADERS := -I$(LIBFT)

SRCS	:= src/error.c \
src/main.c \


OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)
libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(HEADERS) $(LINK) -o $(NAME)
	@echo "Compiling So_long..."

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re, libft