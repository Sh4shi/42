TARGET = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -pthread

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re:
	fclean all
