#include "solver.h"

int lineval(int side, int opponent) {
    if ((side && opponent) || !(side || opponent)) return 0;
    if (side) {
        switch (side) {
            case 2:
                return 3;
                break;
            case 3:
                return 99;
                break;
            default:
                return 1;
                break;
        }
    } else {
        switch (opponent) {
            case 2:
                return -3;
                break;
            case 3:
                return -99;
                break;
            default:
                return -1;
                break;
        }
    }
}

int evaluate(NCBoard *position) {
    unsigned short side, opponent;
    if (position->side == NOUGHTS) {
        side = position->noughts;
        opponent = position->crosses;
    } else {
        side = position->crosses;
        opponent = position->noughts;
    }
    int srow1, srow2, srow3, scol1, scol2, scol3, sdia1, sdia2;
    srow1 = srow2 = srow3 = scol1 = scol2 = scol3 = sdia1 = sdia2 = 0;
    int orow1, orow2, orow3, ocol1, ocol2, ocol3, odia1, odia2;
    orow1 = orow2 = orow3 = ocol1 = ocol2 = ocol3 = odia1 = odia2 = 0;

    int score = 0;
    for (int i = 0; i < 9; ++i) {
        switch (i) {
            case 0:
                if (side & 1) {
                    ++srow1;
                    ++scol1;
                    ++sdia1;
                } else if (opponent & 1) {
                    ++orow1;
                    ++ocol1;
                    ++odia1;
                } 
                break;
            case 1:
                if ((side >> i) & 1) {
                    ++srow1;
                    ++scol2;
                } else if ((opponent >> i) & 1) {
                    ++orow1;
                    ++ocol2;
                } 
                break;
            case 2:
                if ((side >> i) & 1) {
                    ++srow1;
                    ++scol3;
                    ++sdia2;
                } else if ((opponent >> i) & 1) {
                    ++orow1;
                    ++ocol3;
                    ++odia2;
                } 
                score += lineval(srow1, orow1);
                break;
            case 3:
                if ((side >> i) & 1) {
                    ++srow2;
                    ++scol1;
                } else if ((opponent >> i) & 1) {
                    ++orow2;
                    ++ocol1;
                } 
                break;
            case 4:
                if ((side >> i) & 1) {
                    ++srow2;
                    ++scol2;
                    ++sdia1;
                    ++sdia2;
                } else if ((opponent >> i) & 1) {
                    ++orow2;
                    ++ocol2;
                    ++odia1;
                    ++odia2;
                } 
                break;
            case 5:
                if ((side >> i) & 1) {
                    ++srow2;
                    ++scol3;
                } else if ((opponent >> i) & 1) {
                    ++orow2;
                    ++ocol3;
                }
                score += lineval(srow2, orow2);
                break;
            case 6:
                if ((side >> i) & 1) {
                    ++srow3;
                    ++scol1;
                    ++sdia2;
                } else if ((opponent >> i) & 1) {
                    ++orow3;
                    ++ocol1;
                    ++odia2;
                }
                score += lineval(scol1, ocol1);
                score += lineval(sdia2, odia2);
                break;
            case 7:
                if ((side >> i) & 1) {
                    ++srow3;
                    ++scol2;
                } else if ((opponent >> i) & 1) {
                    ++orow3;
                    ++ocol2;
                }
                score += lineval(scol2, ocol2);
                break;
            case 8:
                if ((side >> i) & 1) {
                    ++srow3;
                    ++scol3;
                    ++sdia1;
                } else if ((opponent >> i) & 1) {
                    ++orow3;
                    ++ocol3;
                    ++odia1;
                }
                score += lineval(srow3, orow3);
                score += lineval(scol3, ocol3);
                score += lineval(sdia1, odia1);
                break;
        }
    }
    return score;
}

int movegen(NCBoard *position, int *moves) {
    int count = 0;
    for (int i = 0; i < 9; ++i) {
        if (legal(position, i)) {
            moves[count] = i;
            ++count;
        }
    }
    return count;
}

int negamax(NCBoard *position, int depth) {
    if (depth == 0) return evaluate(position);

    int max = -8;
    int score;

    int moves[9];
    int movelist_len = movegen(position, moves);
    for (int i = 0; i < movelist_len; ++i) {
        play(position, moves[i]);
        score = -negamax(position, depth - 1);
        unmake(position);
        if (score > max) {
            max = score;
        }
    }
    return max;
}
