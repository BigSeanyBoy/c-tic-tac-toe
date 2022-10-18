// #include "board.h"
#include "solver.h"

int main() {
    NCBoard position;
    position.side = NOUGHTS;
    position.noughts = 0;
    position.crosses = 0;
    position.nbmoves = 0;

    int move;
    while (!gameover(&position)) {
        display(&position);
        printf("Enter move: ");
        scanf("%d", &move);
        while ((getchar()) != '\n');
        if (legal(&position, move)) {
            play(&position, move);
        } else if (move == -1) {
            return 0;
        } else {
            printf("Illegal move\n");
        }
    }

    display(&position);

    if (alignment(position.noughts) || alignment(position.crosses)) {
        position.side == CROSSES ? printf("Noughts win!\n\n") : printf("Crosses win!\n\n");
    } else {
        printf("Draw...\n\n");
    }

    return 0;
}