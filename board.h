#ifndef BOARD
#define BOARD

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

#endif