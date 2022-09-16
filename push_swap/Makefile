TARGET = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
RM = rm -rf

LIBFT = ./libft
SRCS = ./source/check/input_check.c \
		./source/check/input_check2.c \
		./source/push_swap.c \
		./source/list_menagement/set_list.c \
		./source/list_menagement/list_utility.c \
		./source/utility/utility.c \
		./source/utility/utility2.c \
		./source/utility/algorithms.c \
		./source/utility/lis_utility.c \
		./source/utility/push_algorithms_utility.c \
		./source/list_menagement/move/move.c \
		./source/list_menagement/move/move2.c \
		./source/list_menagement/move/double_move.c \
		./source/start_move.c \
		./source/three.c \
		./source/five.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(TARGET)

$(TARGET) : $(OBJS)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -o $(TARGET)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)
	make fclean -C $(LIBFT)

re: fclean all
