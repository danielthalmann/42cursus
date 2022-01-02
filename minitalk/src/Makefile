
SERVER=server

CLIENT=client

SRC_CLIENT=client.c

SRC_SERVER=server.c

OBJS_CLIENT=${SRC_CLIENT:.c=.o}
OBJS_SERVER=${SRC_SERVER:.c=.o}

CFLAGS=-Wall -Wextra -Werror

CC=gcc

all: ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SERVER}
	${CC} $< -o $@

${CLIENT}: ${OBJS_CLIENT}
	${CC} $< -o $@

clean: 
	rm -f ${OBJS_CLIENT} ${OBJS_SERVER}

fclean: clean
	rm -f ${CLIENT} ${SERVER}

re: fclean all

.PHONY: clean re fclean all
