#ifndef SOLVER
#define SOLVER

#include <stdio.h>
#include <math.h>

#define KNOTS 0
#define CROSSES 1

#define KNOTS_CHAR 'O'
#define CROSSES_CHAR 'X'

typedef struct kcboard {
    unsigned short player;
    unsigned short position;
    unsigned short mask;
} Board;

void print_board(Board board);

void generate_moves(Board board, unsigned short side, unsigned short *result);

#endif