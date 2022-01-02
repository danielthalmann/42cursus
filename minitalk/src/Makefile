
NAME=cs

SRC=main.c

OBJS=${SRC:.c=.o}

CFLAGS=-Wall -Wextra -Werror

CC=gcc

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

all: ${NAME}

${NAME}: ${OBJS}
	${CC} $< -o $@

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean re fclean all
