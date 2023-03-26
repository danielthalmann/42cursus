
NAME=mini_serv

SRCS=main.final.3.c

OBJS=${SRCS:c=o}

CFLAGS=-Werror -Wextra -Wall -g

$(NAME) : $(OBJS)
	$(CC) $^ -o $(NAME)

run : $(NAME)
	./$(NAME) 8000