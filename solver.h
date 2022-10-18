#ifndef SOLVER
#define SOLVER

#include "board.h"

int evaluate(NCBoard *position);
int movegen(NCBoard *position, int *moves);
int negamax(NCBoard *position, int depth);

#endif