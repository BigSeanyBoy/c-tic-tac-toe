#include "board.h"

/*
 * Check if a move is legal for a given position
 */
int legal(const NCBoard *position, int move) {
    if (move < 0 || move > 8) return 0;
    if ((position->noughts >> move) & 1) return 0;
    if ((position->crosses >> move) & 1) return 0;
    return 1;
}

/*
 * Play a specified move for a given board state.
 *
 * Place the current sides marker, change sides, add the move to the list of
 * played moves, and increment the number of moves played this game.
 */
void play(NCBoard *position, int move) {
    switch (position->side) {
        case NOUGHTS:
            position->noughts += (1 << move);
            break;
        case CROSSES:
            position->crosses += (1 << move);
            break;
    }
    position->side = position->side ^ 1;
    position->movelist[position->nbmoves] = move;
    ++position->nbmoves;
}

/*
 * Play a sequence of moves specified by a string of integersl
 */
void playseq(NCBoard *position, char* seq) {
    int seqlen = 0;
    for (int c = 0; seq[c] != '\0'; ++c) ++seqlen;
    for (int i = 0; i < seqlen; ++i) {
        play(position, seq[i] - '0');
    }
}

/*
 * Undo the most recently played move. 
 * 
 * Effectively the opposite of the "play" function above.
 */
void unmake(NCBoard *position) {
    --position->nbmoves;
    int move = position->movelist[position->nbmoves];
    position->side = position->side ^ 1;
    switch (position->side) {
        case NOUGHTS:
            position->noughts -= (1 << move);
            break;
        case CROSSES:
            position->crosses -= (1 << move);
            break;
    }
}

/*
 * Check for an alignment of 3 pieces of the same side. A position consisting
 * of only one piece type is given so there is no need to check the side.
 */
int alignment(unsigned short position) {
    if (position & (position >> 1) & (position >> 2) & (1 | 8 | 64)) return 1;
    if (position & (position >> 3) & (position >> 6) & (1 | 2 | 4)) return 1;
    if (position & (position >> 4) & (position >> 8) & 1) return 1;
    if (position & (position >> 2) & (position >> 4) & 4) return 1;
    return 0;
}

/*
 * Check if the game is over. End game conditions are an alignment (win/loss)
 * or a full board without an alignment (draw).
 */
int gameover(NCBoard *position) {
    if (alignment(position->noughts)) return 1;
    if (alignment(position->crosses)) return 1;
    for (int i = 0; i < 9; ++i) {
        if (legal(position, i)) {
            return 0;
        }
    }
    return 1;
}

/*
 * Print the given position.
 */
void display(const NCBoard *position) {
    printf("\n ");
    for (int i = 0; i < 9; ++i) {
        if (i) {
            i % 3 == 0 ? printf("\n-----------\n ") : printf(" | ");
        }

        if ((position->noughts >> i) & 1) {
            printf("%s", NOUGHTS_CHAR);
        } else if ((position->crosses >> i) & 1) {
            printf("%s", CROSSES_CHAR);
        } else {
            printf("%d", i);
        }
    }
    printf("\n\n");
}
