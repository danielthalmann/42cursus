
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html

NAME=humans

SRCS=main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJS=$(SRCS:cpp=o)

CXX=gcc

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

LDFLAGS=-lstdc++

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

all : $(NAME)

clean :
	rm -fr $(OBJS)

fclean : clean
	rm -fr $(NAME)

re : fclean all

run : $(NAME)
	./$(NAME)

