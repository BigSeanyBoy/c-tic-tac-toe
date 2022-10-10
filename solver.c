#include <stdio.h>

#define KNOTS_CHAR 'O'
#define CROSSES_CHAR 'X'

enum turn {
    Knots,
    Crosses
};

unsigned short state = 0;
unsigned short knots_loc = 0;
unsigned short crosses_loc = 0;

enum turn player = Knots;

void print_board() {
    int pos_status;

    printf("\n ");
    for (int i = 0; i < 9; ++i) {
        if (i) {
            i % 3 == 0 ? printf("\n-----------\n ") : printf(" | ");
        }

        pos_status = (state >> i) & 1;
        if (pos_status) {
            pos_status & (knots_loc >> i) ? printf("%c", KNOTS_CHAR) : printf("%c", CROSSES_CHAR);
        } else {
            printf(" ");
        }
    }
    printf("\n\n");
}

int main() {
    print_board();

    return 0;
}
