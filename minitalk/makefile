
CC	= gcc
LIBC	= ar rc
CFLAGS	+= -Wall -Werror -Wextra

LIBFT = libft

SRC = client.c \
		server.c \

OBJS	= $(src:.c=.o)

NAME	= minitalk.a

.PHONY:	all clean fclean re

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
		rm -f *~ $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all 