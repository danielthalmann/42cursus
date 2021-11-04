
NAME=libftprintf.a

SRC=ft_itoa.c ft_strlen.c ft_strchr.c ft_printf.c

TEST=../tests/ft_printf_test.c

OBJS=${SRC:.c=.o}

CC=gcc

CFLAG=-Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAG} $< -c -o $@

${NAME}: ${OBJS}
	ar rsv ${NAME} ${OBJS}

all: ${NAME}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

test: ${NAME} ${TEST}
	${CC} ${CFLAG} ${TEST} -I. -L. -lftprintf -o test