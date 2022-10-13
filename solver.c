#include "solver.h"

void print_board(Board board) {
    printf("\n ");
    for (int i = 0; i < 9; ++i) {
        if (i) {
            i % 3 == 0 ? printf("\n-----------\n ") : printf(" | ");
        }

        if ((board.knots >> i) & 1) {
            printf("%c", KNOTS_CHAR);
        } else if ((board.crosses >> i) & 1) {
            printf("%c", CROSSES_CHAR);
        } else {
            printf(" ");
        }
    }
    printf("\n\n");
}

void generate_moves(Board board, unsigned short side, unsigned short *result) {
    
}

// int main() {
//     Board board;
//     board.knots = 0;
//     board.crosses = 0;

//     print_board(board);

//     return 0;
// }
