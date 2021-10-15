
NAME=test
CC=gcc
SRCS=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
     ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	 ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	 ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	 ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	 ft_atoi.c \
	 ft_calloc.c ft_strdup.c \
	 ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	 ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	 ft_putendl_fd.c ft_putnbr_fd.c
OBJS=${SRCS:.c=.o}
COMPILE_FLAG=-Wall -Wextra -Werror
LINKED_FLAG=
NORMINETTE=/home/daniel/.local/bin/norminette

%.o: %.c
	${CC} ${CONPILE_FLAG} -c $< -o $@

all:
	@echo 'specify the function to test'

ft_atoi:
	${CC} ${CONPILE_FLAG} ../src/ft_atoi.c ../src/ft_isdigit.c ft_atoi_test.c faker.c -o ${NAME}
	${NORMINETTE} ../src/ft_atoi.c
	./test

ft_bzero:
	${CC} ${CONPILE_FLAG} ../src/ft_bzero.c ft_bzero_test.c faker.c -o ${NAME}
	${NORMINETTE} ../src/ft_bzero.c
	./test

ft_calloc:
	${CC} ${CONPILE_FLAG} ../src/ft_calloc.c ../src/ft_bzero.c ft_calloc_test.c faker.c -o ${NAME}
	${NORMINETTE} ../src/ft_calloc.c
	./test

clean:
	rm ${OBJS}

fclean: clean
	rm ${NAME}

re: fclean all
