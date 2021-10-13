
NAME=libft.a
CC=gcc
SRCS=isalpha.c
OBJS=${SRCS:.c=.o}
COMPILE_FLAG=-Wall -Wextra -Werror
LINKED_FLAG=

%.o: %.c
	${CC} ${CONPILE_FLAG} -c $< -o $@

${NAME}: ${OBJS}
	ar rsv $@ ${OBJS} 

all: ${NAME}

clean:
	rm ${OBJS}

fclean: clean
	rm ${NAME}

re: fclean all


