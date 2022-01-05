
SERVER=server

CLIENT=client

SRC_CLIENT=client/client.c

SRC_SERVER=server/ft_bzero.c \
           server/server.c

OBJS_CLIENT=${SRC_CLIENT:.c=.o}
OBJS_SERVER=${SRC_SERVER:.c=.o}

CFLAGS=-Wall -Wextra -Werror

CC=gcc

all: ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SERVER}
	${CC} ${OBJS_SERVER} -o $@

${CLIENT}: ${OBJS_CLIENT}
	${CC} ${OBJS_CLIENT} -o $@

clean: 
	rm -f ${OBJS_CLIENT} ${OBJS_SERVER}

fclean: clean
	rm -f ${CLIENT} ${SERVER}

re: fclean all

norm: 
	norminette server/*.h server/*.c
	norminette client/*.h client/*.c

.PHONY: clean re fclean all
