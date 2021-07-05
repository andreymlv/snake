
SRC = main.cc window.cc

OBJS = ${SRC:.cc=.o}

CC = g++

COMPILER_FLAGS = -Wall -Wextra -g

LINKER_FLAGS = -lSDL2

OBJ_NAME = snake

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
