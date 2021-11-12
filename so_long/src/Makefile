NAME=so_long

SRC=main.c

HEADER=${SRC:.c=.h}

OBJS=${SRC:.c=.o}

CFLAGS=-Wall -Wextra -Wall

LDFLAGS=

LOADLIBES=-L${LIBFT_PATH} -L${LIBMLX_PATH}

LDLIBS=-lft -lmlx

CC=gcc

TARGET_ARCH=

MINETTE=norminette

LIBFT_PATH=./libft
LIBFT=${LIBFT_PATH}/libft.a

LIBMLX_PATH=./minilibx_opengl
LIBMLX=${LIBMLX_PATH}/libmlx.a

${NAME}: ${OBJS} ${LIBFT} ${LIBMLX}
	$(CC) $(LDFLAGS) $(TARGET_ARCH) ${OBJS} $(LOADLIBES) $(LDLIBS) -o $@

all: ${NAME}

clean: 
	rm -fr ${OBJS}
	make clean -C ${LIBFT_PATH}
	make clean -C ${LIBMLX_PATH}

fclean: clean
	rm -fr ${NAME}
	make fclean -C ${LIBFT_PATH}

libft: ${LIBFT}

${LIBFT}:
	make -C ${LIBFT_PATH}

libmlx: ${LIBMLX}

${LIBMLX}:
	make -C ${LIBMLX_PATH}

re: fclean all

norm: 
	${MINETTE} ${HEADER}

.PHONY : ${LIBFT} ${LIBMLX} clean fclean all re