NAME = push_swap
LIBFT = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAG = -c
OFLAG = -o
IFLAG = -I
MAKE = make -c
MAKE_CLEAN = make clean -c
MAKE_FCLEAN =  make fclean -c
MKDIR =  mkdir -p
CP =  cp
RM =  rm -f
SRCDIR =  ./source
OBJDIR =  ./objs
INCDIR =  ./include
LIBFTDIR =  ./libft
FILES =         init_list.c \
                set_list.c \
			 	input_check.c \
			 	utility.c \
			 	push_swap.c \

SRCS = $(foreach FILE, $(FILES), $(shell find $(SRCDIR) -name $(FILE)))

OBJS = $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(IFLAG) $(INCDIR) $(CFLAG) $(OFLAG) $@ $< 

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(OFLAG) $(NAME)

$(LIBFT):
	@$(MAKE) $(LIBFTDIR)
	@$(CP) $(LIBFTDIR)/$(LIBFT) .

clean:
	@$(RM) $(OBJDIR) $(OBJS) $(LIBFT)
	@$(RM) ./libft.a
	@$(MAKE_CLEAN) $(LIBFTDIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ./libft.a
	@$(MAKE_FCLEAN) $(LIBFTDIR)

re: fclean all

.PHONY: all norm clean fclean re