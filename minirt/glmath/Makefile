NAME=libglmath.a

SRCS=scene.c vector.c color.c ray.c primitives/sphere.c

OBJS=$(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CC=gcc

CFLAGS=-Wall -Werror -Wextra -I $(INCLUDE_PATH)

# detection du systeme d'exploitation
UNAME_S := $(shell uname -s)
# pour linux
ifeq ($(UNAME_S),Linux)
	CFLAGS += -lm
endif

# path
LIB_PATH=./lib/
INCLUDE_PATH=./include/
SRC_PATH=./srcs/


$(NAME): $(OBJS)
	ar rsv $(addprefix $(LIB_PATH), $(NAME)) $(OBJS)
	
clean: 
	rm -f $(OBJS)
		
fclean: clean
	rm -f $(addprefix $(LIB_PATH), $(NAME))

re: fclean $(NAME)
