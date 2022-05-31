#NAME = push_swap
#LIBFT = libft.a
#CC = gcc
#CFLAGS = -Wall -Wextra -Werror
#CFLAG = -c
#OFLAG = -o
#IFLAG = -I
#MAKE = make -C
#MAKE_CLEAN = make clean -C
#MAKE_FCLEAN =  make fclean -C
#MKDIR =  mkdir -p
#CP =  cp
#RM =  rm -rf
#SRCDIR =  ./source
#OBJDIR =  ./objs
#INCDIR =  ./include
#LIBFTDIR =  ./libft
#FILES =         init_list.c \
#                set_list.c \
#			 	input_check.c \
#			 	utility.c \
#			 	push_swap.c \
#				radix.c \
#
#SRCS = $(foreach FILE, $(FILES), $(shell find $(SRCDIR) -name $(FILES)))
#
#OBJS = $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))
#
#$(OBJDIR)/%.o: $(SRCDIR)/%.c
#	@$(MKDIR) $(@D)
#	@$(CC) $(CFLAGS) $(IFLAG) $(INCDIR) $(CFLAG) $(OFLAG) $@ $< 
#
#all: $(NAME)
#
#$(NAME): $(OBJS) $(LIBFT)
#	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(OFLAG) $(NAME)
#
#$(LIBFT):
#	@$(MAKE) $(LIBFTDIR)
#	@$(CP) $(LIBFTDIR)/$(LIBFT) .
#
#clean:
#	@$(RM) $(OBJDIR) $(OBJS) $(LIBFT)
#	@$(RM) ./libft.a
#	@$(MAKE_CLEAN) $(LIBFTDIR)
#
#fclean: clean
#	@$(RM) $(NAME)
#	@$(RM) ./libft.a
#	@$(MAKE_FCLEAN) $(LIBFTDIR)
#
#re: fclean all
#.PHONY: all norm clean fclean re

TARGET = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT = ./libft
SRCS = ./source/check/input_check.c \
	./source/push_swap.c \
	./source/list_menagement/set_list.c \
	./source/list_menagement/list_utility.c \
	./source/utility/utility.c \
	./source/utility/radix.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(TARGET)

$(TARGET) : $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -o $(TARGET)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)
	make fclean -C $(LIBFT)

re: fclean all
