NAME=libmathgraphic.a

SRCS=vector.c

OBJS=$(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CC=gcc

CFLAGS=-Wall -Werror -Wextra -I $(INCLUDE_PATH)

# path
LIB_PATH=./lib/
INCLUDE_PATH=./include/
SRC_PATH=./src/


$(NAME): $(OBJS)
	ar rsv $(addprefix $(LIB_PATH), $(NAME)) $(OBJS)