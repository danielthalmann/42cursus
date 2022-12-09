NAME=pipex
SOURCES=main.c
SRCS_PATH=src/
SRCS=$(addprefix $(SRCS_PATH), $(SOURCES))
OBJS=$(SRCS:.c=.o)

PID_NAME=pid
PID_SOURCES=pid.c
PID_SRCS_PATH=src/
PID_SRCS=$(addprefix $(PID_SRCS_PATH), $(PID_SOURCES))
PID_OBJS=$(PID_SRCS:.c=.o)


CC=gcc
CFLAGS=

.phony : all

all: $(NAME) $(PID_NAME)0 $(PID_NAME)1

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)


$(PID_NAME)0 : $(PID_OBJS)
	$(CC) $(PID_OBJS) -o $(PID_NAME)0

$(PID_NAME)1 : $(PID_OBJS)
	$(CC) $(PID_OBJS) -o $(PID_NAME)1
