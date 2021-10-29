
NAME=test

SRC_FOLDER=../src/

SRC=${SRC_FOLDER}get_next_line.c ${SRC_FOLDER}get_next_line_utils.c

CFLAG=-Wall -Wextra -Werror -L${SRC_FOLDER}

CC=gcc

${NAME}:
	${NORMINETTE} ${SRC}
	${NORMINETTE} ${SRC_FOLDER}get_next_line.h
	${CC} ${CFLAG} ${SRC} main.c -o ${NAME}
	./test

test: ${FUNCTIONS}

fclean: clean
	rm ${NAME}

re: fclean all