#include "board.h"

void movegen(struct NCBoard *position) {
    int moves[9];
    int j = 0;
    for (int i = 0; i < 9; ++i) {
        if ((position->noughts >> i) & 1 || (position->crosses >> i) & 1) {
            moves[j] = i;
        }
    }
}

void play(struct NCBoard *position, int move) {
    switch (position->side) {
        case NOUGHTS:
            position->noughts += (1 << move);
            break;
        case CROSSES:
            position->crosses += (1 << move);
            break;
    }
    position->side = position->side ^ 1;
}

void playseq(struct NCBoard *position, char* seq) {
    int seqlen = 0;
    for (int c = 0; seq[c] != '\0'; ++c) ++seqlen;
    for (int i = 0; i < seqlen; ++i) {
        play(position, seq[i] - '0');
    }
}

void display(struct NCBoard *position) {
    printf("\n ");
    for (int i = 0; i < 9; ++i) {
        if (i) {
            i % 3 == 0 ? printf("\n-----------\n ") : printf(" | ");
        }

        if ((position->noughts >> i) & 1) {
            printf("%c", NOUGHTS_CHAR);
        } else if ((position->crosses >> i) & 1) {
            printf("%c", CROSSES_CHAR);
        } else {
            printf(" ");
        }
    }
    printf("\n\n");
}

int main() {
    struct NCBoard position;
    position.side = NOUGHTS;
    position.noughts = 0;
    position.crosses = 0;

    display(&position);
    playseq(&position, "012345678");
    display(&position);

    return 0;
}