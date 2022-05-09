TARGET	=	push_swap
CC		=	gcc
CFLAGS 	=	-Wall -Wextra -Werror
SRC 	=	./source/push_swap.c \
			./source/check/input_check.c \
			./source/utility/utility.c \
			./include/list_menagement/init_list.c \
			./include/list_menagement/set_list.c \
OBJ		=	$(SRC:.c=.o)
RM		=	rm -rf

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all