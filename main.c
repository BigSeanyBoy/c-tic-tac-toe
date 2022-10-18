#include "solver.h"

#define AI 0
#define USER 1

int main() {
    NCBoard position;
    position.side = NOUGHTS;
    position.noughts = 0;
    position.crosses = 0;
    position.nbmoves = 0;

    int player;
    printf("Would you like to go first? [y/n]: ");
    player = getchar() == 'y' ? USER : AI;
    while ((getchar()) != '\n');

    int move;
    while (!gameover(&position)) {
        if (player) {
            display(&position);
            printf("Enter move: ");
            scanf("%d", &move);
            while ((getchar()) != '\n');
            if (legal(&position, move)) {
                play(&position, move);
                player = AI;
            } else if (move == -1) {
                return 0;
            } else {
                printf("Illegal move\n");
            }
        } else {
            int max = -999;
            int score;

            int moves[9];
            int movelist_len = movegen(&position, moves);
            for (int i = 0; i < movelist_len; ++i) {
                play(&position, moves[i]);
                score = -negamax(&position);
                unmake(&position);
                if (score > max) {
                    max = score;
                    move = moves[i];
                }
            }
            play(&position, move);
            player = USER;
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