
NAME=ft_container
STDNAME=std_container

SRCS=./src/main.cpp

OBJS=$(SRCS:cpp=o)

OBJS_FOLDER=./obj/

CXX=c++

CXXFLAGS=-Wall -Wextra -Werror -Wfatal-errors -std=c++98 -I./include

LDFLAGS=-lstdc++ -lm

$(NAME) : clean $(OBJS_FOLDER) $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

$(STDNAME) : CXXFLAGS += -DCOMPILE_LIB_STD
$(STDNAME) : $(OBJS_FOLDER) $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

$(OBJS_FOLDER) :
	mkdir obj

all : 
	$(MAKE) clean
	$(MAKE) $(NAME)
	$(MAKE) clean
	$(MAKE) $(STDNAME)
	./$(NAME) 10 > ft.out.txt
	./$(STDNAME) 10 > std.out.txt
	$ diff -c ft.out.txt std.out.txt


clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

test :
	$(MAKE) -C ./tests run

.phony : tree map test

