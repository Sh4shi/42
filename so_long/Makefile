TARGET = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)

LIBDIR = ./lib
LIBFTDIR = $(LIBDIR)/libft

LIBSTATIC = $(LIBFTDIR)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: libs $(TARGET)

libs:
	make -C $(LIBFTDIR)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(LIBSTATIC) $(OBJS)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(TARGET)
	make fclean -C $(LIBFTDIR)

re: fclean all


