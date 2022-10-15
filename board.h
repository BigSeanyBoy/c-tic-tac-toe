#ifndef BOARD
#define BOARD

#define NOUGHTS_CHAR 'O'
#define CROSSES_CHAR 'X'

enum piece {
    NOUGHTS = 0,
    CROSSES = 1
};

struct NCBoard {
    enum piece side;
    unsigned short noughts;
    unsigned short crosses;
};

int* movegen(struct NCBoard *position);
void play(struct NCBoard *position, int move);
void playseq(struct NCBoard* position, char* seq);

#endif