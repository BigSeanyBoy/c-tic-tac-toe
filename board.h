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
    int movelist[9];
    enum piece side;
    int nbmoves;
    unsigned short noughts;
    unsigned short crosses;
} NCBoard;

int legal(const NCBoard *position, int move);
void play(NCBoard *position, int move);
void unmake(NCBoard *position);
void playseq(NCBoard *position, char* seq);
int alignment(unsigned short position);
void display(const NCBoard *position);

#endif