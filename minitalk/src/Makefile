
NAME=cs

SRC=main.c

OBJS=${SRC:.c=.o}

CFLAGS=

CC=gcc

all: ${NAME}

${NAME}: ${OBJS}
	${CC} $< -o $@

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean re fclean all
