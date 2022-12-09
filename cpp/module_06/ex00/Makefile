
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html

NAME=convert

SRCS=main.cpp Convert.cpp Scalar.cpp ScalarInt.cpp ScalarChar.cpp ScalarFloat.cpp ScalarDouble.cpp

OBJS=$(SRCS:cpp=o)

CXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

LDFLAGS=-lstdc++ -lm

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
