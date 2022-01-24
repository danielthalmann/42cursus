NAME=philo

SRC=philo/philo.c

OBJS=${SRC:%.c=%.o}

FLAGS=-Wall -Wetra -Werror -g 

CC=gcc

philo/${NAME}: ${OBJS}
	${CC} ${OBJS} -lpthread -o philo/${NAME}

all: ${NAME}

test: 
	${CC} tests/main.c -lpthread -o tests/test
