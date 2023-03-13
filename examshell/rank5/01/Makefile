

NAME=warlock
SRCS=ASpell.cpp  ATarget.cpp  Dummy.cpp  Fwoosh.cpp  Warlock.cpp main.cpp
OBJS=$(SRCS:cpp=o)
CXXFLAGS=-Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(CXX) $^ -o $@

run:
	./$(NAME) | cat -e

clean:
	rm -f ${OBJS}
	rm -f ${NAME}

re : clean $(NAME)
