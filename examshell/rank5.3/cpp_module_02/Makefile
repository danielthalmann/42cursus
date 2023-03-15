NAME=test

SRCS=ASpell.cpp \
ATarget.cpp \
Dummy.cpp \
Fireball.cpp \
Fwoosh.cpp \
main.cpp \
Polymorph.cpp \
BrickWall.cpp \
SpellBook.cpp \
TargetGenerator.cpp

OBJS=${SRCS:cpp=o}

CXXFLAGS=-Wall -Werror -Wextra


$(NAME) : $(OBJS)
	$(CXX) $^ -o $(NAME)

clean :
	rm -f $(OBJS)
	rm -f $(NAME)

re : clean $(NAME)

