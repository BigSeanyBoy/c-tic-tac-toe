#include "solver.h"

int evaluate(NCBoard *position) {
    switch (position->side) {
        case NOUGHTS:
            if (alignment(position->noughts)) return 1;
            if (alignment(position->crosses)) return -1;
            return 0;
        case CROSSES:
            if (alignment(position->crosses)) return 1;
            if (alignment(position->noughts)) return -1;
            return 0;
    }
}

int movegen(NCBoard *position, int *moves) {
    int count = 0;
    for (int i = 0; i < 9; ++i) {
        if (legal(position, i)) {
            moves[count] = i;
            ++count;
        }
    }
    return count;
}

int negamax(NCBoard *position) {
    if (gameover(position)) return evaluate(position);

    int max = -999;
    int score;

    int moves[9];
    int movelist_len = movegen(position, moves);
    for (int i = 0; i < movelist_len; ++i) {
        play(position, moves[i]);
        score = -negamax(position);
        unmake(position);
        if (score > max) {
            max = score;
        }
    }
    return max;
}
