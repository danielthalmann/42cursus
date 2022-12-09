
NAME		= json.a

SRCS		= Json.cpp	

SRC_PATH	= ./srcs/

OBJS=$(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

LDFLAGS=-lstdc++ -lm

${NAME}: ${OBJS}
	ar rsv $@ ${OBJS} 

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

run : $(NAME)
	./$(NAME)
