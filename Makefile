# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:55:12 by igaguila          #+#    #+#              #
#    Updated: 2024/06/19 16:17:30 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server

SRC_C = client.c
SRC_S = server.c

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf.a

all: $(PRINTF) $(NAME_S) $(NAME_C)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME_S): $(OBJ_S) 
	$(CC) $(CFLAGS) $(OBJ_S) $(PRINTF) -o $(NAME_S)

$(NAME_C): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)

clean:
	@make -C ${PRINTF_DIR} clean
	@rm -f $(OBJ_S) $(OBJ_C)

fclean: clean
	@make -C ${PRINTF_DIR} fclean
	@rm -f $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re