
NAME=test
CC=gcc
FUNCTIONS=ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
		  ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy \
		  ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
		  ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri # ft_strjoin \
		  ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr \
		  ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper 
OBJS=${SRCS:.c=.o}
SRC_FOLDER=../src/
COMPILE_FLAG=-Wall -Wextra -Werror -g
LINKED_FLAG=
NORMINETTE=norminette

%.o: %.c
	${CC} ${COMPILE_FLAG} -c $< -o $@

all:
	@echo 'specify the name of function to test or tape "make test" for testing all function'

ft_atoi:
	${NORMINETTE} ${SRC_FOLDER}ft_atoi.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_atoi.c ${SRC_FOLDER}ft_isdigit.c ft_atoi_test.c faker.c -o ${NAME}
	./test

ft_bzero:
	${NORMINETTE} ${SRC_FOLDER}ft_bzero.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_bzero.c ft_bzero_test.c faker.c -o ${NAME}
	./test

ft_calloc:
	${NORMINETTE} ${SRC_FOLDER}ft_calloc.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_calloc.c ${SRC_FOLDER}ft_bzero.c ft_calloc_test.c faker.c -o ${NAME}
	./test

ft_isalnum:
	${NORMINETTE} ${SRC_FOLDER}ft_isalnum.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_isalnum.c ${SRC_FOLDER}ft_isdigit.c ${SRC_FOLDER}ft_isalpha.c ft_isalnum_test.c faker.c -o ${NAME}
	./test

ft_isalpha:
	${NORMINETTE} ${SRC_FOLDER}ft_isalpha.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_isalpha.c ft_isalpha_test.c faker.c -o ${NAME}
	./test

ft_isascii:
	${NORMINETTE} ${SRC_FOLDER}ft_isascii.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_isascii.c ft_isascii_test.c faker.c -o ${NAME}
	./test

ft_isdigit:
	${NORMINETTE} ${SRC_FOLDER}ft_isdigit.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_isdigit.c ft_isdigit_test.c faker.c -o ${NAME}
	./test

ft_isprint:
	${NORMINETTE} ${SRC_FOLDER}ft_isprint.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_isprint.c ft_isprint_test.c faker.c -o ${NAME}
	./test

ft_itoa:
	${NORMINETTE} ${SRC_FOLDER}ft_itoa.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_itoa.c ${SRC_FOLDER}ft_calloc.c ${SRC_FOLDER}ft_bzero.c ft_itoa_test.c faker.c -o ${NAME}
	./test

ft_memchr:
	${NORMINETTE} ${SRC_FOLDER}ft_memchr.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_memchr.c ft_memchr_test.c faker.c -o ${NAME}
	./test

ft_memcmp:
	${NORMINETTE} ${SRC_FOLDER}ft_memcmp.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_memcmp.c ft_memcmp_test.c faker.c -o ${NAME}
	./test

ft_memcpy:
	${NORMINETTE} ${SRC_FOLDER}ft_memcpy.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_memcpy.c ft_memcpy_test.c faker.c -o ${NAME}
	./test

ft_memmove:
	${NORMINETTE} ${SRC_FOLDER}ft_memmove.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_memmove.c ft_memmove_test.c faker.c -o ${NAME}
	./test

ft_memset:
	${NORMINETTE} ${SRC_FOLDER}ft_memset.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_memset.c ft_memset_test.c faker.c -o ${NAME}
	./test

ft_putchar_fd:
	${NORMINETTE} ${SRC_FOLDER}ft_putchar_fd.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_putchar_fd.c ft_putchar_fd_test.c faker.c -o ${NAME}
	./test

ft_putendl_fd:
	${NORMINETTE} ${SRC_FOLDER}ft_putendl_fd.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_putendl_fd.c ft_putendl_fd_test.c faker.c -o ${NAME}
	./test

ft_putnbr_fd:
	${NORMINETTE} ${SRC_FOLDER}ft_putnbr_fd.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_putnbr_fd.c ft_putnbr_fd_test.c faker.c -o ${NAME}
	./test

ft_putstr_fd:
	${NORMINETTE} ${SRC_FOLDER}ft_putstr_fd.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_putstr_fd.c ft_putstr_fd_test.c faker.c -o ${NAME}
	./test

ft_split:
	${NORMINETTE} ${SRC_FOLDER}ft_split.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_split.c  ${SRC_FOLDER}ft_putnbr_fd.c ft_split_test.c faker.c -o ${NAME}
	./test

ft_strchr:
	${NORMINETTE} ${SRC_FOLDER}ft_strchr.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_strchr.c ft_strchr_test.c faker.c -o ${NAME}
	./test

ft_strdup:
	${NORMINETTE} ${SRC_FOLDER}ft_strdup.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_strdup.c ${SRC_FOLDER}ft_strlen.c ft_strdup_test.c faker.c -o ${NAME}
	./test

ft_striteri:
	${NORMINETTE} ${SRC_FOLDER}ft_striteri.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_striteri.c ft_striteri_test.c faker.c -o ${NAME}
	./test




ft_tolower:
	${NORMINETTE} ${SRC_FOLDER}ft_tolower.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_tolower.c ft_tolower_test.c faker.c -o ${NAME}
	./test

ft_toupper:
	${NORMINETTE} ${SRC_FOLDER}ft_toupper.c
	${CC} ${COMPILE_FLAG} ${SRC_FOLDER}ft_toupper.c ft_toupper_test.c faker.c -o ${NAME}
	./test


test: ${FUNCTIONS}

fclean: clean
	rm ${NAME}

re: fclean all
