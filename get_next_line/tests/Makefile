
NAME=test

SRC_FOLDER=../src/

BUFFER_SIZE=10000000

SRC=${SRC_FOLDER}get_next_line.c ${SRC_FOLDER}get_next_line_utils.c \
	get_next_line_test.c
OBJ=${SRC:.c=.o}

CFLAG=-Wall -Wextra -Werror -I${SRC_FOLDER} -D BUFFER_SIZE=${BUFFER_SIZE} -g
LFLAG=-L${SRC_FOLDER} -fsanitize=address

NORMINETTE=ls

CC=gcc

%.o: %.c
	${CC} ${CFLAG} -c $< -o $@ 

${NAME}: ${OBJ}
	${NORMINETTE} ${SRC}
	${NORMINETTE} ${SRC_FOLDER}get_next_line.h
	${CC} ${LFLAG} ${OBJ} -o ${NAME}
	./${NAME} "case00.txt" | cat -e

all: ${NAME}

test: ${FUNCTIONS}

clean: 
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

