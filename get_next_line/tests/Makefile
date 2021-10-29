
NAME=test

SRC_FOLDER=../src/

SRC=${SRC_FOLDER}get_next_line.c ${SRC_FOLDER}get_next_line_utils.c \
	main.c
OBJ=${SRC:.c=.o}

CFLAG=-Wall -Wextra -Werror -I${SRC_FOLDER}
LFLAG=-L${SRC_FOLDER}

NORMINETTE=ls

CC=gcc

%.o: %.c
	${CC} ${CFLAG} -c $< -o $@ 

${NAME}: ${OBJ}
	${NORMINETTE} ${SRC}
	${NORMINETTE} ${SRC_FOLDER}get_next_line.h
	${CC} ${LFLAG} ${OBJ} -o ${NAME}
	./${NAME}

all: ${NAME}

test: ${FUNCTIONS}

clean: 
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

