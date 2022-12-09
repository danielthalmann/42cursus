NAME=philo

SRC=philo.c \
	ft_philo_factory.c \
	ft_philo_thread.c \
	ft_atoi_pos.c

OBJS=${SRC:%.c=%.o}

FLAGS=-Wall -Wetra -Werror -g 

CC=gcc

${NAME}: ${OBJS}
	${CC} ${OBJS} -lpthread -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}
	rm -f ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}

re: fclean all

norm: 
	norminette *.c *.h
