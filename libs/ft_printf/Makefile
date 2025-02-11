OBJS 		=	ft_printf.o ft_conversions.o ft_print_char.o ft_print_str.o \
				ft_print_ptr.o ft_print_dig.o ft_utils.o ft_putnbr_base.o \
				ft_print_udig.o ft_print_hex.o ft_print_module.o

CC 			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM 			=	rm -f
AR			=	ar rc

NAME		= libftprintf.a

LIBFT		= libft.a

LIBFT_DIR	= ../libft

all:		$(NAME)

$(NAME):	$(OBJS)
			@make bonus -C $(LIBFT_DIR)
			cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
			$(AR) $(NAME) ${OBJS}

%.o:		%.c
			${CC} ${CFLAGS} -c $< -o $@

clean:
			@make clean -C $(LIBFT_DIR)
			${RM} ${OBJS} ${OBJS_DEPS}

fclean:		clean
			@make fclean -C $(LIBFT_DIR)
			${RM} ${NAME}

bonus: 		all

re:			fclean all

.PHONY:		all clean fclean re

.SILENT:
