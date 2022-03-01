
CC = gcc

CFLAGS += -Wall -Werror -Wextra

LIBFT = libft

SRC			= ft_printf.c \
				ft_printf_utility.c \
				ft_printlike.c \
				ft_printlike_utils.c \
				ft_printlike_utility.c \
				ft_utility.c \

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

.PHONY:	all clean fclean re

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rcs ${NAME} ${OBJS}
		
all: $(NAME)

bonus : all

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
		rm -f *~ $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all clean bonus