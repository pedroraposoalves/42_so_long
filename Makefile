#########COLORS##########
RESET			= \033[0m
BLACK			= \033[1;30m
RED				= \033[1;31m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
BLUE			= \033[1;34m
PURPLE			= \033[1;35m
CYAN			= \033[1;36m
WHITE			= \033[1;37m

##########FLAGS##########
CC				= cc
CPFLAGS			= -Wall -Wextra -Werror -g #-fsanitize=address
RM				= rm -rf
AR				= ar -rcs
MK				= --no-print-directory

##########MLX##########
MLX_PATH 		= libs/mlx
MLX_LIB			= ${MLX_PATH}/libmlx_Linux.a
MLX				= -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

##########GNL##########
GNL_PATH		= libs/get_next_line
GNL_LIB			= ${GNL_PATH}/libgnl.a
GNL				= -L ${GNL_PATH} -lgnl

##########FT_PRINTF & LIBFT##########
PRINTF_PATH		= libs/ft_printf
PRINTF_LIB		= ${PRINTF_PATH}/libftprintf.a
PRINTF			= -L ${PRINTF_PATH} -lftprintf
LIBFT_PATH		= libs/libft
LIBFT_LIB		= ${LIBFT_PATH}/libft.a
LIBFT			= -L ${LIBFT_PATH} -lft


##########FILES & FOLDERS##########
NAME			= so_long
SRC				= src
OBJ_DIR			= objs
_FILES			= map_init map_upload validations game exit move
OBJS			= $(_FILES:%=%.o)
TARGET			= $(addprefix $(OBJ_DIR)/, $(OBJS))
DEPS			= includes


##########RULES##########
all		: 		$(NAME)

$(NAME)			:${MLX_LIB} ${GNL_LIB} ${PRINTF_LIB} $(OBJ_DIR) $(TARGET) main.c
					echo "[$(CYAN) Compiling $(RESET)] $(GREEN)Main$(RESET)"
					$(CC) $(CPFLAGS) main.c $(TARGET) $(LIBFT) $(GNL) $(MLX) $(PRINTF) -o $(NAME) -I $(DEPS)

					echo "$(GREEN)Done.$(RESET)"

${MLX_LIB}		:
					echo "[$(CYAN)Compiling$(RESET)] $(CPFLAGS) $(GREEN)MLX$(RESET)"
					@make ${MK} -sC ${MLX_PATH}

${GNL_LIB}		:
					echo "[$(CYAN)Compiling$(RESET)] $(CPFLAGS) $(GREEN)GNL$(RESET)"
					@make ${MK} -sC ${GNL_PATH}

${PRINTF_LIB}	:
					echo "[$(CYAN)Compiling$(RESET)] $(CPFLAGS) $(GREEN)PRINTF$(RESET)"
					@make bonus ${MK} -sC ${PRINTF_PATH}

$(OBJ_DIR)/%.o	:$(SRC)/%.c
					echo "[$(CYAN)Compiling$(RESET)] $(CPFLAGS) $(GREEN)$<$(RESET)"
					$(CC) $(CPFLAGS) -c $< -o $@ -I $(DEPS)

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)

clean			:
					${RM} main.o
					echo "[$(RED)Deleted$(RESET)] $(GREEN)MAIN$(RESET)"
					@make clean ${MK} -C ${MLX_PATH}
					echo "[$(RED)Deleted$(RESET)] $(GREEN)MLX$(RESET)"
					@make clean ${MK} -C ${GNL_PATH}
					echo "[$(RED)Deleted$(RESET)] $(GREEN)GNL$(RESET)"
					@make clean ${MK} -C ${PRINTF_PATH}
					echo "[$(RED)Deleted$(RESET)] $(GREEN)FT_PRINTF$(RESET)"
					$(RM) $(OBJ_DIR)
					echo "[$(RED)Deleted$(RESET)] $(GREEN)OBJS$(RESET)"


fclean			: clean
					${RM} ${NAME}
					echo "[$(RED)Deleted$(RESET)] $(GREEN)${NAME}$(RESET)"
					@make fclean ${MK} -C ${GNL_PATH}
					@make fclean ${MK} -C ${PRINTF_PATH}
					echo "[$(RED)Deleted$(RESET)] $(GREEN)*.a Libs$(RESET)"

re				: fclean all

.PHONY:		all clean fclean re

.SILENT:
