
NAME=libftprintf.a

SRC=ft_print_utils_two.c ft_print_utils.c ft_print_hex_fd.c ft_print_unsigned_dec_fd.c ft_print_integer_fd.c ft_print_pointer_fd.c ft_print_string_fd.c ft_print_char_fd.c ft_itoa.c ft_ltoa.c ft_ltox.c ft_strlen.c ft_strchr.c ft_printf.c

BONUS=ft_print_utils_two.c ft_print_utils.c ft_print_hex_fd.c ft_print_unsigned_dec_fd.c ft_print_integer_fd.c ft_print_pointer_fd.c ft_print_string_fd.c ft_print_char_fd.c ft_itoa.c ft_ltoa.c ft_ltox.c ft_strlen.c ft_strchr.c ft_printf.c

TEST=../tests/ft_printf_test.c

OBJS=${SRC:.c=.o}

OBJSBONUS=${BONUS:.c=.o}

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

bonus:  ${OBJSBONUS}
	ar rsv ${NAME} ${OBJSBONUS}

test: ${NAME} ${TEST}
	${CC} ${CFLAG} ${TEST} -I. -L. -lftprintf -o test