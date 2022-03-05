NAME=libglmath.a

SRCS=vector.c color.c ray.c

OBJS=$(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CC=gcc

CFLAGS=-Wall -Werror -Wextra -I $(INCLUDE_PATH)

# path
LIB_PATH=./lib/
INCLUDE_PATH=./include/
SRC_PATH=./srcs/


$(NAME): $(OBJS)
	ar rsv $(addprefix $(LIB_PATH), $(NAME)) $(OBJS)
	
clean: 
	rm -f $(OBJS)
		
fclean: clean
	rm -f $(addprefix $(LIB_PATH), $(NAME))

re: fclean $(NAME)
