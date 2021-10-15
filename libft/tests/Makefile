
NAME=test
CC=gcc
FUNCTIONS=ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
		  ft_isdigit ft_isprint ft_itoa #ft_memchr ft_memcmp ft_memcpy \
		  ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
		  ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat \
		  ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr \
		  ft_strtrim ft_substr ft_tolower ft_toupper 
OBJS=${SRCS:.c=.o}
SRC_FOLDER=../src/
COMPILE_FLAG=-Wall -Wextra -Werror
LINKED_FLAG=
NORMINETTE=/home/daniel/.local/bin/norminette

%.o: %.c
	${CC} ${CONPILE_FLAG} -c $< -o $@

all:
	@echo 'specify the name of function to test or tape "make test" for testing all function'

ft_atoi:
	${NORMINETTE} ${SRC_FOLDER}ft_atoi.c
	${CC} ${CONPILE_FLAG} ${SRC_FOLDER}ft_atoi.c ${SRC_FOLDER}ft_isdigit.c ft_atoi_test.c faker.c -o ${NAME}
	./test

ft_bzero:
	${NORMINETTE} ${SRC_FOLDER}ft_bzero.c
	${CC} ${CONPILE_FLAG} ${SRC_FOLDER}ft_bzero.c ft_bzero_test.c faker.c -o ${NAME}
	./test

ft_calloc:
	${NORMINETTE} ${SRC_FOLDER}ft_calloc.c
	${CC} ${CONPILE_FLAG} ${SRC_FOLDER}ft_calloc.c ${SRC_FOLDER}ft_bzero.c ft_calloc_test.c faker.c -o ${NAME}
	./test

ft_isalnum:
	${NORMINETTE} ${SRC_FOLDER}ft_isalnum.c
	${CC} ${CONPILE_FLAG} ${SRC_FOLDER}ft_isalnum.c ${SRC_FOLDER}ft_isdigit.c ${SRC_FOLDER}ft_isalpha.c ft_isalnum_test.c faker.c -o ${NAME}
	./test

ft_isalpha:
	${NORMINETTE} ${SRC_FOLDER}ft_isalpha.c
	${CC} ${CONPILE_FLAG} ${SRC_FOLDER}ft_isalpha.c ft_isalpha_test.c faker.c -o ${NAME}
	./test

ft_isascii:
	${NORMINETTE} ${SRC_FOLDER}ft_isascii.c
	${CC} ${CONPILE_FLAG} ${SRC_FOLDER}ft_isascii.c ft_isascii_test.c faker.c -o ${NAME}
	./test

ft_isdigit:
	${NORMINETTE} ${SRC_FOLDER}ft_isdigit.c
	${CC} ${CONPILE_FLAG} ${SRC_FOLDER}ft_isdigit.c ft_isdigit_test.c faker.c -o ${NAME}
	./test

ft_isprint:
	${NORMINETTE} ${SRC_FOLDER}ft_isprint.c
	${CC} ${CONPILE_FLAG} ${SRC_FOLDER}ft_isprint.c ft_isprint_test.c faker.c -o ${NAME}
	./test

ft_itoa:
	${NORMINETTE} ${SRC_FOLDER}ft_itoa.c
	${CC} ${CONPILE_FLAG} ${SRC_FOLDER}ft_itoa.c ${SRC_FOLDER}ft_calloc.c ${SRC_FOLDER}ft_bzero.c ft_itoa_test.c faker.c -o ${NAME}
	./test

test: ${FUNCTIONS}

fclean: clean
	rm ${NAME}

re: fclean all
