# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 03:05:41 by sdell-un          #+#    #+#              #
#    Updated: 2022/03/16 03:06:57 by sdell-un         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c

NAME_SERVER = server
NAME_CLIENT = client

OBJ_SRV = server.o utils.o
OBJ_CLIENT = client.o utils.o

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_SRV)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SRV)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT)


clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SRV)

fclean:	clean
	rm -f $(OBJ_CLIENT) $(OBJ_SRV) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: server client all re fclean clean