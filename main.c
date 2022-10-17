// #include "board.h"
#include "solver.h"

int main() {
    NCBoard position;
    position.side = NOUGHTS;
    position.noughts = 0;
    position.crosses = 0;

    int move;
    int endgame = 0;
    while (!endgame) {
        printf("\nHeuristic Score: %d", evaluate(&position));
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
        switch (position.side) {
            case CROSSES:
                endgame = alignment(position.noughts);
                break;
            case NOUGHTS:
                endgame = alignment(position.crosses);
                break;
        }
    }

    printf("\nHeuristic Score: %d", evaluate(&position));
    display(&position);
    position.side == CROSSES ? printf("Noughts win!\n\n") : printf("Crosses win!\n\n");

    return 0;
}