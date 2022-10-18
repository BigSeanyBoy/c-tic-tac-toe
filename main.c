#include "solver.h"

#define AI 0
#define USER 1

int gameloop() {
    NCBoard position;
    position.side = NOUGHTS;
    position.noughts = 0;
    position.crosses = 0;
    position.nbmoves = 0;

    int player;
    printf("\nWould you like to go first? [y/n]: ");
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
                return 1;
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
        position.side == CROSSES ? printf("Noughts win!\n") : printf("Crosses win!\n");
    } else {
        printf("Draw...\n");
    }

    return 0;
}

int main() {
    for (;;) {
        if (gameloop()) break;
        printf("\nWould you like to play again? [y/n]: ");
        if (getchar() != 'y') break;
        while ((getchar()) != '\n');
    }

    return 0;
}