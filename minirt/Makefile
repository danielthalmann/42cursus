NAME=minirt

SRCS=main.c

OBJS=$(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CC=gcc

CFLAGS=-Wall -Werror -Wextra -I $(INCLUDE_PATH) -I $(GL_INCLUDE) -I $(MLX_INCLUDE)

# path

GL_LIB_PATH	 =./glmath/
GL_LIB		 = $(addprefix $(GL_LIB_PATH), lib)
GL_INCLUDE	 = $(addprefix $(GL_LIB_PATH), include)
GL_FLAG		 = glmath

MLX_LIB_PATH = ./minilibx_linux/
MLX_LIB		 = $(MLX_LIB_PATH)
MLX_INCLUDE  = $(MLX_LIB_PATH)
MLX_FLAG	 = mlx

LDFLAGS = -lXext -lX11 -lz

# detection du systeme d'exploitation
UNAME_S := $(shell uname -s)
# pour linux
ifeq ($(UNAME_S),Linux)
	LDFLAGS = -lXext -lX11 -lz

	MLX_LIB_PATH = ./minilibx_linux/
	MLX_LIB		 = $(MLX_LIB_PATH)
	MLX_INCLUDE  = $(MLX_LIB_PATH)
	MLX_FLAG	 = mlx

endif
# pour macOS
ifeq ($(UNAME_S),Darwin)

	LDFLAGS = -lz -framework OpenGL -framework AppKit

	MLX_LIB_PATH = ./minilibx_opengl/
	MLX_LIB		 = $(MLX_LIB_PATH)
	MLX_INCLUDE  = $(MLX_LIB_PATH)
	MLX_FLAG	 = mlx

endif

GL			 = glmath
INCLUDE_PATH =./include/
SRC_PATH	 =./srcs/

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(GL_LIB_PATH)
	$(MAKE) -C $(MLX_LIB_PATH)
	$(CC) $(OBJS) -l$(GL_FLAG) -l$(MLX_FLAG) -L$(GL_LIB) -L$(MLX_LIB) $(LDFLAGS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(GL_LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all
