NAME=push_swap

SRC=main.c \
	push_swap_utils.c \
	push_swap_loader.c \
	push_swap_cmd.c \
	push.c \
	swap.c \
	rotate.c \
	compare.c \
	reverse_rotate.c \
	checker.c \
	list2.c \
	list2b.c

HEADER=${SRC:.c=.h}

OBJS=${SRC:.c=.o}

LIBFT_PATH=./libft
LIBFT=${LIBFT_PATH}/libft.a

CFLAGS=-Wall -Wextra -Wall -I${LIBFT_PATH} -g

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
	${MINETTE} ./*.c ./*.h

run: all
	./${NAME}

.PHONY : clean fclean all re