#ifndef SOLVER
#define SOLVER

#include <stdio.h>

#define KNOTS 0
#define CROSSES 1

#define KNOTS_CHAR 'O'
#define CROSSES_CHAR 'X'

typedef struct kcboard {
    unsigned short knots;
    unsigned short crosses;
} Board;

void print_board(Board board);

void generate_moves(Board board, unsigned short side, unsigned short *result);

#endif