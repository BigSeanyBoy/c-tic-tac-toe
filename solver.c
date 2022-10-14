#include "solver.h"

void print_board() {
    printf("\n ");
    for (int i = 0; i < 9; ++i) {
        if (i) {
            i % 3 == 0 ? printf("\n-----------\n ") : printf(" | ");
        }

        if ((board.mask >> i) & 1) {
            if ((board.position >> i) & 1) {
                board.player == KNOTS ? printf("%c", KNOTS_CHAR) : printf("%c", CROSSES_CHAR);
            } else {
                board.player == KNOTS ? printf("%c", CROSSES_CHAR) : printf("%c", KNOTS_CHAR);
            }
        } else {
            printf("%d", i);
        }
    }
    printf("\n\n");
}

int can_play(int pos) {
    return !((board.mask >> pos) & 1);
}

void play(int pos) {
    if (!((board.mask >> pos) & 1)) {
        board.player = board.player == KNOTS ? CROSSES : KNOTS;
        board.position ^= board.mask;
        board.mask += (1 << pos);
    }
}

// int main() {
//     board.player = KNOTS;
//     board.position = 0;
//     board.mask = 0;

//     print_board(board);

//     return 0;
// }
