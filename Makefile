TARGET = out

CFLAGS = -g -Wall
CC = clang $(CFLAGS)

ODIR = obj
_OBJ = main.o board.o solver.o mcts.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main.o board.o solver.o mcts.o $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

main.o:
	$(CC) -c -o obj/main.o main.c

board.o:
	$(CC) -c -o obj/board.o board.c

solver.o:
	$(CC) -c -o obj/solver.o solver.c

mcts.o:
	$(CC) -c -o obj/mcts.o mcts.c
