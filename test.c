#include "solver.h"

#define KNRM "\x1b[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"

/* sample boards used for testing */
Board empty, knots_turn, crosses_turn;

void move_gen_check(unsigned short result[], unsigned short check[], char* name) {
    for (int i = 0; i < 9; ++i) {
        if (result[i] != check[i]) {
            printf("%s[FAILED]%s move generation: %s\n", KRED, KNRM, name);
            return;
        } 
    }

    printf("%s[PASSED]%s move generation: %s\n", KGRN, KNRM, name);
}

/* move generation tests */
void test_empty() {
    unsigned short check[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    unsigned short result[9];
    generate_moves(empty, KNOTS, result);

    move_gen_check(result, check, "empty board");
}

void test_knots_turn() {
    unsigned short check[9] = {21, 37, 69, 133, 256, 0, 0, 0, 0};
    unsigned short result[9];
    generate_moves(knots_turn, KNOTS, result);

    move_gen_check(result, check, "knots turn");
}

void test_crosses_turn() {
    unsigned short check[9] = {3, 5, 9, 17, 33, 129, 0, 0, 0};
    unsigned short result[9];
    generate_moves(crosses_turn, CROSSES, result);

    move_gen_check(result, check, "crosses turn");
}

int main() {
    empty.knots = 0;
    empty.crosses = 0;

    knots_turn.knots = 5;
    knots_turn.crosses = 10;

    crosses_turn.knots = 320;
    crosses_turn.crosses = 1;

    test_empty();
    test_knots_turn();
    test_crosses_turn();

    return 0;
}