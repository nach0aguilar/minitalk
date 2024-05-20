# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:55:12 by igaguila          #+#    #+#              #
#    Updated: 2024/05/20 18:51:13 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server

SRC = server.c client.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) server.o -o server
	@$(CC) $(CFLAGS) client.o -o client

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f server client

re: fclean all

.PHONY: all clean fclean re