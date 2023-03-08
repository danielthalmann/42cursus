

NAME=warlock
SRCS=main.cpp ASpell.cpp  ATarget.cpp  Dummy.cpp  Fwoosh.cpp  Warlock.cp
OBJS=$(SRCS:cpp=o)

$(NAME): $(OBJS)
	$(CXX) $? -o $@

run:
	./$(NAME) | cat -e
