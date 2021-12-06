NAME=push_swap

SRC=main.c \
	swap.c \
	list2.c

HEADER=${SRC:.c=.h}

OBJS=${SRC:.c=.o}

LIBFT_PATH=./libft
LIBFT=${LIBFT_PATH}/libft.a

CFLAGS=-Wall -Wextra -Wall -I${LIBFT_PATH} -g -DDEBUG=1

LDFLAGS=

LDLIBS=-lft

CC=gcc

TARGET_ARCH=

MINETTE=norminette

${NAME}: ${LIBFT} ${OBJS}
	$(CC) $(LDFLAGS) $(TARGET_ARCH) ${OBJS} -L${LIBFT_PATH} -lft -o $@

all: ${NAME}

libft: ${LIBFT}

${LIBFT}:
	make -C ${LIBFT_PATH}

clean: 
	rm -fr ${OBJS}
	make clean -C ${LIBFT_PATH}

fclean: clean
	rm -fr ${NAME}
	make fclean -C ${LIBFT_PATH}

re: fclean all

norm: 
	${MINETTE} ${HEADER} ${SRC}

run: all
	./${NAME}

.PHONY : clean fclean all re