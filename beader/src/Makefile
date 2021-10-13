NAME=beader
CC=gcc
SRCS=beader.c
OBJS=${SRCS:.c=.o}
COMPILE_FLAG=-Wall -Wextra -Werror
LINKED_FLAG=

%.o: %.c
	${CC} ${CONPILE_FLAG} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${LINKED_FLAG} -o $@ ${OBJS} 

all: ${NAME}

clean:
	rm ${OBJS}

fclean:
	rm ${NAME}

re: clean fclean all

# fin
