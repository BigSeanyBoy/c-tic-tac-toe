#include "solver.h"

int negamax(NCBoard *position, int depth) {
    if (depth == 0 || alignment(position)) return evaluate(position);

    int max = -8;
    int score;

    int moves[9];
    int movelist_len = movegen(position, moves);
    for (int i = 0; i < movelist_len; ++i) {
        play(position, moves[i]);
        score = -negamax(position, depth - 1);
        unmake(position);
        if (score > max) {
            max = score;
        }
    }
    return max;
}
