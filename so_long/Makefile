TARGET = so_long
CC = gcc
CFLAGS = -g -fsanitize=address#-Wall -Wextra -Werror
RM = rm -f
SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)

LIBDIR = ./lib
LIBFTDIR = $(LIBDIR)/libft
MLXDIR = $(LIBDIR)/minilibx_mms_20200219

LIBSTATIC = $(LIBFTDIR)/libft.a
LIBDINAMIC = $(MLXDIR)/libmlx.dylib

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I ./include -I $(MLXDIR)

all: $(TARGET)

$(TARGET) : libs $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(LIBSTATIC) $(OBJS) -framework OpenGL -framework AppKit -lz -L $(MLXDIR) -lmlx

libs:
	make bonus -C $(LIBFTDIR)
	make -C $(MLXDIR)
	cp $(LIBDINAMIC) .

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)

fclean: clean
	$(RM) $(TARGET)
	make fclean -C $(LIBFTDIR)
	$(RM) libmlx.dylib
	$(RM) $(LIBDINAMIC)

re: fclean all

norme:
	norminette $(SRCS) $(LIBFTDIR)
