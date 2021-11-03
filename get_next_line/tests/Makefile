
NAME=test

SRC_FOLDER=../src/

BUFFER_SIZE=1

SRC=${SRC_FOLDER}get_next_line.c ${SRC_FOLDER}get_next_line_utils.c \

BONUS=${SRC_FOLDER}get_next_line_bonus.c ${SRC_FOLDER}get_next_line_utils_bonus.c \
	
OBJ=${SRC:.c=.o}

BONUS_OBJ=${BONUS:.c=.o}

CFLAG=-Wall -Wextra -Werror -I${SRC_FOLDER} -D BUFFER_SIZE=${BUFFER_SIZE} -g -fsanitize=address
LFLAG=-L${SRC_FOLDER} -fsanitize=address

NORMINETTE=norminette

CC=gcc

%.o: %.c
	${CC} ${CFLAG} -c $< -o $@ 

${NAME}: ${OBJ} get_next_line_test.o
	${CC} ${LFLAG} ${OBJ} get_next_line_test.o -o ${NAME}
	./${NAME} "case00.txt" | cat -e

all: ${NAME}

test: ${FUNCTIONS}

clean: 
	rm -f ${OBJ} get_next_line_test.o
	rm -f ${BONUS_OBJ} get_next_line_bonus_test.o

fclean: clean
	rm -f ${NAME}

re: fclean all

norm:
	${NORMINETTE} ${SRC}
	${NORMINETTE} ${SRC_FOLDER}get_next_line.h

norm_bonus:
	${NORMINETTE} ${BONUS}
	${NORMINETTE} ${SRC_FOLDER}get_next_line_bonus.h

bonus: ${BONUS_OBJ} get_next_line_bonus_test.o
	${CC} ${LFLAG} ${BONUS_OBJ} get_next_line_bonus_test.o -o ${NAME}
	./${NAME} | cat -e

rebonus: clean bonus
	
