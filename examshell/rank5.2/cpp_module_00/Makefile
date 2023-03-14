
NAME=test
SRCS=main.cpp \
     Warlock.cpp
OBJS=${SRCS:cpp=o}

CXXFLAGS=-Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CXX) $^ -o $(NAME)

clean:
	rm -f $(OBJS)

re: clean $(NAME)
	

