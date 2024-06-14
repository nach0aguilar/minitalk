# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:55:12 by igaguila          #+#    #+#              #
#    Updated: 2024/06/14 19:44:01 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server

SRC_C = client.c
SRC_S = server.c

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

OBJ = $(SRC:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF = ${PRINTF_DIR}/ft_printf.a

all: $(OBJ_S) $(OBJ_C)
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(PRINTF) $(SRC_S) -o $(NAME_S)
	@$(CC) $(CFLAGS) $(SRC_C) -o $(NAME_C)

clean:
	@make -C ${PRINTF_DIR} clean
	@rm -f $(OBJ_S) $(OBJ_C)

fclean: clean
	@make -C ${PRINTF_DIR} fclean
	@rm -f $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re