

NAME=warlock
SRCS=Warlock.cpp main.cpp
OBJS=$(SRCS:cpp=o)

$(NAME): $(OBJS)
	$(CXX) $^ -o $@

run:
	./$(NAME) | cat -e
