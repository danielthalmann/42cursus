
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html

NAME=horde

SRCS=main.cpp zombieHorde.cpp Zombie.cpp

OBJS=$(SRCS:cpp=o)

CXX=gcc

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

LDFLAGS=-lstdc++

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

all : $(NAME)

clean :
	rm $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all

run : $(NAME)
	./$(NAME)
