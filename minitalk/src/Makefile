
SERVER=server

CLIENT=client

SRC_CLIENT=cli/client.c

SRC_SERVER=serv/ft_bzero.c \
           serv/server.c

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
	norminette serv/*.h serv/*.c
	norminette cli/*.h cli/*.c

.PHONY: clean re fclean all
