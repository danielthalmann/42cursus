
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html

NAME=animal

SRCS=AMateria.cpp Cure.cpp Ice.cpp Character.cpp ICharacter.cpp IMateriaSource.cpp MateriaSource.cpp main.cpp

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

debug : CXXFLAGS += -DDEBUG
debug : re

run : $(NAME)
	./$(NAME)
