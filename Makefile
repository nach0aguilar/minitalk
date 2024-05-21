# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:55:12 by igaguila          #+#    #+#              #
#    Updated: 2024/05/21 14:25:06 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server

SRC_C = src/client.c
SRC_S = src/server.c

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = includes/libft
LIBFT = ${LIBFT_DIR}/libft.a

PRINTF_DIR = includes/ft_printf
PRINTF = ${PRINTF_DIR}/ft_printf.a

all: $(OBJ_S) $(OBJ_C)
	@make -C includes/libft
	@make -C includes/ft_printf
	@$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(SRC_S) -o $(NAME_S)
	@$(CC) $(CFLAGS) $(LIBFT) $(SRC_C) -o $(NAME_C)

clean:
	@make -C ${LIBFT_DIR} clean
	@make -C ${PRINTF_DIR} clean
	@rm -f $(OBJ_S) $(OBJ_C)

fclean: clean
	@make -C ${LIBFT_DIR} fclean
	@make -C ${PRINTF_DIR} fclean
	@rm -f $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re