#ifndef MCTS_H_
#define MCTS_H_

#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "./board.h"
#include "./solver.h"

#define C 2

typedef struct node{
        int move;

        int wins;
        int visits;

        struct node *parent;
        int nbchild;
        struct node *children[256];

        float uct;
} * nodeptr;

nodeptr initnode();
void addchild(nodeptr parent, nodeptr child);
void freenode(nodeptr node);

void _uct(nodeptr node);

nodeptr selection(nodeptr node);

int search(NCBoard *position);

#endif /* MCTS_H_ */
