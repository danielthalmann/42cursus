NAME=test
CC=gcc

FUNCTIONS=ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
		  ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy \
		  ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
		  ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
		  ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr \
		  ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper 

OBJS=${SRCS:.c=.o}

SRC_FOLDER=../src/

COMPILE_FLAG=-Wall -Wextra -Werror -g -L${SRC_FOLDER} -lft

COMPILE_BSD_FLAG=

ifneq ($(OS),Windows_NT)
	UNAME := $(shell uname)
	ifeq ($(UNAME), Linux)
		COMPILE_BSD_FLAG=-lbsd 
	endif
endif

LINKED_FLAG=
NORMINETTE=norminette

all:
	@echo ' '
	@echo 'specify the name of function to test or tape "make test" for testing all function'
	@echo 'the valid function is > '
	@echo '${FUNCTIONS}' 
	@echo ' '

os: 
	@echo $(shell uname -s)

lib:
	make -C $(SRC_FOLDER)

${FUNCTIONS}: lib
	${NORMINETTE} ${SRC_FOLDER}ft_atoi.c
	${CC} ${COMPILE_FLAG} ${COMPILE_BSD_FLAG} $@_test.c faker.c -o ${NAME}
	./test

test: ${FUNCTIONS}

fclean: clean
	rm ${NAME}

re: fclean all

.PHONY: clean test ${FUNCTIONS}
