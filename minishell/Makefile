TARGET = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft
SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(TARGET)

$(TARGET) : $(OBJS)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -lreadline -o $(TARGET)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)
	make fclean -C $(LIBFT)

re: fclean all