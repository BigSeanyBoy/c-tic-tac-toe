#ifndef SOLVER
#define SOLVER

#include <stdio.h>

#define KNOTS 0
#define CROSSES 1

#define KNOTS_CHAR 'O'
#define CROSSES_CHAR 'X'

typedef struct kcboard {
    int player;
    unsigned short position;
    unsigned short mask;
} Board;

Board board;

void print_board();
int can_play(int pos);
void play(int pos);

// void generate_moves(Board board, unsigned short side, unsigned short *result);

#endif