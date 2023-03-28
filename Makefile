NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = -I includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = main.c \
       utils.c \
       child.c

SRCS_BONUS = main.c \
             utils.c \
             Error.c \
             init_struct.c \
             get_next_line_utils.c \
             get_next_line.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})
OBJS_BONUS = $(addprefix ${OBJS_DIR}/bonus/, ${SRCS_BONUS:%.c=%.o})

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D} >/dev/null
	@${CC} ${CFLAGS} ${INC_DIR} -I ${LIBFT_INC} -c $< -o $@ >/dev/null

${OBJS_DIR}/bonus/%.o: bonus/%.c
	@mkdir -p ${@D} >/dev/null
	@${CC} ${CFLAGS} ${INC_DIR} -I ${LIBFT_INC} -c $< -o $@ >/dev/null

${NAME}: ${OBJS}
	@make -C ${LIBFT_PATH} >/dev/null
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} -o ${NAME} >/dev/null
	@echo "\033[1;32mCompilation successful: $(NAME)\033[0m"

bonus: ${OBJS_BONUS}
	@make -C ${LIBFT_PATH} >/dev/null
	@${CC} ${CFLAGS} ${OBJS_BONUS} ${LIBFT_LIB} -o ${NAME} >/dev/null
	@echo "\033[1;32mBonus compilation successful: $(NAME)\033[0m"

clean:
	@make clean -C ${LIBFT_PATH} >/dev/null
	@${RM} ${OBJS_DIR} >/dev/null
	@echo "\033[1;33mObject files deleted.\033[0m"

fclean: clean
	@make fclean -C ${LIBFT_PATH} >/dev/null
	@@${RM} ${NAME} >/dev/null
	@echo "\033[1;31m$(NAME) deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus
