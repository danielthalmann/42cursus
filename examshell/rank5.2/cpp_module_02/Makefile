
NAME=test
SRCS=main.cpp \
     Warlock.cpp \
     ASpell.cpp \
     ATarget.cpp \
     Fwoosh.cpp \
     Dummy.cpp \
     Fireball.cpp \
     Polymorph.cpp \
     BrickWall.cpp \
     SpellBook.cpp \
     TargetGenerator.cpp \

OBJS=${SRCS:cpp=o}

CXXFLAGS=-Wall -Wextra -Werror -g

$(NAME): $(OBJS)
	$(CXX) $^ -o $(NAME)

clean:
	rm -f $(OBJS)

re: clean $(NAME)
	

