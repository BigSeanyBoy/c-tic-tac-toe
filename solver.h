#ifndef SOLVER
#define SOLVER

#define KNOTS_CHAR 'O'
#define CROSSES_CHAR 'X'

struct KCBoard {
    unsigned short knots;
    unsigned short crosses;
};

void print_board(struct KCBoard board);

#endif