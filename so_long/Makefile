TARGET = so_long
CC = gcc
CFLAGS = -g#-Wall -Wextra -Werror
RM = rm -rf
SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)


LIBDIR = ./lib
LIBFTDIR = $(LIBDIR)/libft
MLXDIR = $(LIBDIR)/minilibx_mms_20200219

LIBSTATIC = $(LIBFTDIR)/libft.a
LIBDINAMIC = $(MLXDIR)/libmlx.dylib

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I ./include -I $(MLXDIR)

all: libs $(TARGET)

libs:
	make bonus -C $(LIBFTDIR)
	make -C $(MLXDIR)
	cp $(LIBDINAMIC) .

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(LIBSTATIC) $(OBJS) -L $(MLXDIR) -lmlx

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)

fclean: clean
	rm -f $(TARGET)
	make fclean -C $(LIBFTDIR)
	rm -f libmlx.dylib

re: fclean all


