NAME=so_long

SRC=main.c \
	game.c \
	input.c \
	player.c \
	player_position.c \
	player_action.c \
	player_render.c \
	map.c \
	map_position.c \
	map_position2.c \
	map_render.c \
	map_validator.c \
	score.c \
	render.c \
	utils.c

HEADER=${SRC:.c=.h}

OBJS=${SRC:.c=.o}

CFLAGS=-Wall -Wextra -g -Wall -I${LIBFT_PATH} -I${LIBMLX_PATH}

LDFLAGS=

LOADLIBES=-L${LIBFT_PATH} -L${LIBMLX_PATH}

LDLIBS=

LIBFT_PATH=./libft
LIBFT=${LIBFT_PATH}/libft.a

LIBMLX_PATH=./minilibx_opengl
LIBMLX=${LIBMLX_PATH}/libmlx.a

ifeq ($(OS),Windows_NT)
	LDLIBS=-lft -lmlx -lXext -lX11 -lz
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LDLIBS=-lft -lmlx -lXext -lX11 -lz
		LIBMLX_PATH=./minilibx_linux
	endif
	ifeq ($(UNAME_S),Darwin)
		LDLIBS=-lft -lmlx -lz -framework OpenGL -framework AppKit
	endif
endif

CC=gcc

TARGET_ARCH=

MINETTE=norminette

${NAME}: ${LIBFT} ${LIBMLX} ${OBJS}
	$(CC) $(LDFLAGS) $(TARGET_ARCH) ${OBJS} $(LOADLIBES) $(LDLIBS) -o $@

all: ${NAME}

clean: 
	rm -fr ${OBJS}
#	make clean -C ${LIBFT_PATH}
#	make clean -C ${LIBMLX_PATH}

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
	${MINETTE} ${HEADER} ${SRC}

run: all
	./${NAME} map/level.ber

.PHONY : ${LIBFT} ${LIBMLX} clean fclean all re