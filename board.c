#include "board.h"

int* movegen(struct NCBoard *position) {
    int moves[9];
    int j = 0;
    for (int i = 0; i < 9; ++i) {
        if ((position->noughts >> i) & 1 || (position->crosses >> i) & 1) {
            moves[j] = i;
        }
    }
    return moves;
}

int main() {
    return 0;
}