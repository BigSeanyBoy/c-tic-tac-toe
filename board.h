#ifndef BOARD
#define BOARD

#include <stdio.h>

#define NOUGHTS_CHAR 'O'
#define CROSSES_CHAR 'X'

enum piece {
    NOUGHTS = 0,
    CROSSES = 1
};

typedef struct {
    enum piece side;
    unsigned short noughts;
    unsigned short crosses;
} NCBoard;

void play(NCBoard *position, int move);
void playseq(NCBoard *position, char* seq);
void display(const NCBoard *position);
int negamax(const NCBoard *position);

#endif