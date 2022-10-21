
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html

NAME=test

NAMESTD=$(NAME)_std
NAMEFT=$(NAME)_ft

SRCS=main2.cpp test_vector.cpp

OBJS=$(SRCS:cpp=o)

CXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -I../include

LDFLAGS=-lstdc++ -lm

$(NAME) :
	$(MAKE) $(NAMESTD)
	$(MAKE) clean
	$(MAKE) $(NAMEFT)

$(NAMESTD) : CXXFLAGS += -DCOMPILE_LIB_STD
$(NAMESTD) : $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

$(NAMEFT) : $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAMESTD)
	rm -f $(NAMEFT)

re : fclean all

debug : CXXFLAGS += -DDEBUG
debug : re run

run : $(NAME)
	time -p ./$(NAMESTD)
	time -p ./$(NAMEFT)
