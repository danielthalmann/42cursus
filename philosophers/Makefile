NAME=philo/philo

SRC=philo/philo.c \
	philo/ft_philo_factory.c \
	philo/ft_philo_thread.c \
	philo/ft_atoi_pos.c

OBJS=${SRC:%.c=%.o}

NAME_BONUS=philo_bonus/philo_bonus

SRC_BONUS=philo_bonus/philo.c \
	philo_bonus/ft_philo_factory.c \
	philo_bonus/ft_philo_thread.c \
	philo_bonus/ft_atoi_pos.c

OBJS_BONUS=${SRC_BONUS:%.c=%.o}

FLAGS=-Wall -Wetra -Werror -g 

CC=gcc

${NAME}: ${OBJS}
	${CC} ${OBJS} -lpthread -o ${NAME}

${NAME_BONUS}: ${OBJS_BONUS}
	${CC} ${OBJS_BONUS} -lpthread -o ${NAME_BONUS}

bonus: ${NAME_BONUS}

all: ${NAME}

test: 
	${CC} tests/main.c -lpthread -o tests/test

clean:
	rm -f ${OBJS}
	rm -f ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}

re: fclean all

norm: 
	norminette philo/*.c philo/*.h
	norminette philo_bonus/*.c philo_bonus/*.h
