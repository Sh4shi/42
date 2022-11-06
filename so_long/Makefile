TARGET = So_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./lib/libft
GETNEXTLINE = ./lib/getnextline
RM = rm -rf
SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

