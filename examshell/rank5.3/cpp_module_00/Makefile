
NAME=test

SRCS=main.cpp \
Warlock.cpp

OBJS=${SRCS:cpp=o}

$(NAME) : $(OBJS)
	$(CXX) $^ -o $(NAME)

clean :
	rm -f $(OBJS)

re : clean $(NAME)
	

