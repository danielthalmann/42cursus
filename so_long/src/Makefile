NAME=so_long

SRC=main.c

HEADER=${SRC:.c=.h}

OBJS=${SRC:.c=.o}

CFLAGS=-Wall -Wextra -Wall

LDFLAGS=

LOADLIBES=-L./libft

LDLIBS=-lft

CC=gcc

TARGET_ARCH=

MINETTE=norminette

LIBFT_PATH=./libft

LIBFT=${LIBFT_PATH}/libft.a

${NAME}: ${OBJS} ${LIBFT}
	$(CC) $(LDFLAGS) $(TARGET_ARCH) ${OBJS} $(LOADLIBES) $(LDLIBS) -o $@

all: ${NAME}

clean: 
	rm -fr ${OBJS}
	make clean -C ${LIBFT_PATH}

fclean: clean
	rm -fr ${NAME}
	make fclean -C ${LIBFT_PATH}

libft: ${LIBFT}

${LIBFT}:
	make re -C ${LIBFT_PATH}

re: fclean all

norm: 
	${MINETTE} ${HEADER}

.PHONY : libft clean fclean all re