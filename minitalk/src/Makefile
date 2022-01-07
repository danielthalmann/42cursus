
SERVER=server

CLIENT=client

SRC_CLIENT=cli/client.c

SRC_SERVER=serv/ft_bzero.c \
           serv/server.c

OBJS_CLIENT=${SRC_CLIENT:.c=.o}
OBJS_SERVER=${SRC_SERVER:.c=.o}

# bonus

SERVER_BONUS=server_bonus

CLIENT_BONUS=client_bonus

SRC_CLIENT_BONUS=cli/client_bonus.c

SRC_SERVER_BONUS=serv/ft_bzero.c \
           		 serv/server_bonus.c

OBJS_CLIENT_BONUS=${SRC_CLIENT_BONUS:.c=.o}
OBJS_SERVER_BONUS=${SRC_SERVER_BONUS:.c=.o}


CFLAGS=-Wall -Wextra -Werror

CC=gcc

all: ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SERVER}
	${CC} ${OBJS_SERVER} -o $@

${CLIENT}: ${OBJS_CLIENT}
	${CC} ${OBJS_CLIENT} -o $@

bonus: ${SERVER_BONUS} ${CLIENT_BONUS}

${SERVER_BONUS}: ${OBJS_SERVER_BONUS}
	${CC} ${OBJS_SERVER_BONUS} -o $@

${CLIENT_BONUS}: ${OBJS_CLIENT_BONUS}
	${CC} ${OBJS_CLIENT_BONUS} -o $@


clean: 
	rm -f ${OBJS_CLIENT} ${OBJS_SERVER}

fclean: clean
	rm -f ${CLIENT} ${SERVER}

re: fclean all

norm: 
	norminette serv/*.h serv/*.c
	norminette cli/*.h cli/*.c

.PHONY: clean re fclean all
