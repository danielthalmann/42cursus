
NAME=libftprintf.a

SRC=ft_itoa.c 

OBJS=${SRC:.c=.o}

CC=gcc

CFLAG=-Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAG} -c -o $< $@

${NAME}: ${OBJS}
	ar rsv ${NAME} ${OBJS}

all: ${NAME}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
