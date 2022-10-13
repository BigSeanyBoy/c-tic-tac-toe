#include "solver.h"

void print_board(Board board) {
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
            printf(" ");
        }
    }
    printf("\n\n");
}

// void generate_moves(Board board, unsigned short side, unsigned short *result) {
//     printf("\t");
//     for (int i = 0; i < 9; ++i) {
//         if (!((board.knots >> i) & 1) && !((board.crosses >> i) & 1)) {
//             if (side == KNOTS) {
//                 result[i] = board.knots | (1 << i);
//             } else {
//                 result[i] = board.crosses | (1 << i);
//             }
//         }
//         printf("%hu ", result[i]);
//     }
//     printf("\n");
// }

int main() {
    Board board;
    board.player = KNOTS;
    board.position = 0;
    board.mask = 0;

    print_board(board);

    return 0;
}
