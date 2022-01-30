NAME=philo

SRC=philo/philo.c \
	philo/ft_philo_factory.c \
	philo/ft_philo_thread.c \
	philo/ft_atoi_pos.c

OBJS=${SRC:%.c=%.o}

FLAGS=-Wall -Wetra -Werror -g 

CC=gcc

philo/${NAME}: ${OBJS}
	${CC} ${OBJS} -lpthread -o philo/${NAME}

all: philo/${NAME}

test: 
	${CC} tests/main.c -lpthread -o tests/test

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f philo/${NAME}

re: fclean all

norm: 
	norminette philo/*.c philo/*.h
