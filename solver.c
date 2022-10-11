#include <stdio.h>

#define KNOTS_CHAR 'O'
#define CROSSES_CHAR 'X'

struct KCBoard {
    unsigned short knots;
    unsigned short crosses;
};

void print_board(struct KCBoard board) {
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

int main() {
    struct KCBoard board;
    board.knots = 0;
    board.crosses = 0;

    print_board(board);

    return 0;
}
