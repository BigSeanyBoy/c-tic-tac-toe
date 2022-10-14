#include "solver.h"

#define KNRM "\x1b[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"

extern Board board;

void test_can_play(int expected[], char* test_name) {
    for (int i = 0; i < 9; ++i) {
        if (can_play(i) != expected[i]) {
            printf("%s[FAILED]%s valid moves: %s\n", KRED, KNRM, test_name);
            return;
        }
    }
    printf("%s[PASSED]%s valid moves: %s\n", KGRN, KNRM, test_name);
}

void test_play(Board expected, char* test_name) {
    if (board.player != expected.player
        || board.position != expected.position
        || board.mask != expected.mask) {
        printf("%s[FAILED]%s play move: %s\n", KRED, KNRM, test_name);
        return;
    }
    printf("%s[PASSED]%s play move: %s\n", KGRN, KNRM, test_name);
}

void test_alignment(int pos, int expected, char* test_name) {
    if (alignment(pos) != expected) {
        printf("%s[FAILED]%s alignment: %s\n", KRED, KNRM, test_name);
        return;
    } else {
        printf("%s[PASSED]%s alignment: %s\n", KGRN, KNRM, test_name);
    }
}

int main() {
    board.player = KNOTS;
    board.position = 0;
    board.mask = 0;

    int expected[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    test_can_play(expected, "empty board");

    play(0);
    play(1);
    play(3);

    test_alignment(2, 0, "non-winning move");
    play(2);

    for (int i = 0; i < 4; ++i) {
        expected[i] = 0;
    }
    test_can_play(expected, "knots move");
    
    Board test_board;
    test_board.player = KNOTS;
    test_board.position = 9;
    test_board.mask = 15;

    test_play(test_board, "knots move");

    test_alignment(6, 1, "winning move");
    play(6);

    expected[6] = 0;
    test_can_play(expected, "crosses move");
    
    test_board.player = CROSSES;
    test_board.position = 6;
    test_board.mask = 79;
    test_play(test_board, "crosses move");

    return 0;
}