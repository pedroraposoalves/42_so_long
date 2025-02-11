##########COLORS##########
RESET = \033[0m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

##########COMMANDS##########
CC = cc
AR = ar rcs
RM = rm -rf

##########CFLAGS##########
CFLAGS = -Wall -Werror -Wextra
MKFLAGS = --no-print-directory

##########FOLDERS##########
DEPS = ../../includes

##########FILES##########
OBJS =	get_next_line.o get_next_line_utils.o

NAME = libgnl.a

##########RULES##########
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $^

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.SILENT:
