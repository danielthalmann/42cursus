
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html

NAME=brain

SRCS=main.cpp

OBJS=$(SRCS:cpp=o)

CXX=gcc

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

LDFLAGS=-lstdc++

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

run : $(NAME)
	./$(NAME)
