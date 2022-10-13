#include "solver.h"

#define KNRM "\x1b[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"

extern Board board;

void test_can_play(int expected[], char* test_name) {
    for (int i = 0; i < 9; ++i) {
        if (can_play(i) != expected[i]) {
            printf("%s[FAILED]%s move generation: %s\n", KRED, KNRM, test_name);
            return;
        }
    }
    printf("%s[PASSED]%s move generation: knots move\n", KGRN, KNRM);
}

int main() {
    board.player = KNOTS;
    board.position = 0;
    board.mask = 0;

    int expected[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    test_can_play(expected, "empty board");

    board.position = 5;
    board.mask = 15;

    for (int i = 0; i < 4; ++i) {
        expected[i] = 0;
    }
    test_can_play(expected, "knots move");

    board.player = CROSSES;
    board.position = 15;
    board.mask = 31;

    expected[4] = 0;
    test_can_play(expected, "crosses move");

    return 0;
}