#ifndef MCTS_H_
#define MCTS_H_

#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

#include "./board.h"
#include "./solver.h"

#define C 1

/*
 * Nodes represent a possible move, and store how many winning games have been
 * played from the move, how many total games have been played from the move,
 * the parent node (the previously played move), the children nodes (all
 * possible moves after this node's move), and the Upper Confidence bounds
 * applied to Trees  which indicates the quality of the move.
 */
typedef struct node{
        int move;

        int wins;
        int visits;

        struct node *parent;
        int nbchild;
        struct node *children[9];
} * nodeptr;

nodeptr initnode();
void addchild(nodeptr parent, nodeptr child);
void freenode(nodeptr node);

float _uct(nodeptr node);

nodeptr selection(nodeptr node);
void expansion(NCBoard *position, nodeptr node);
int rollout(NCBoard *position, nodeptr node);

int search(NCBoard *position);

#endif /* MCTS_H_ */
