#ifndef MCTS_H_
#define MCTS_H_

#include <math.h>
#include <stdlib.h>

#define C 2

typedef struct node{
        int wins;
        int visits;

        struct node *parent;
        struct node *children[256];

        float uct;
} * nodeptr;

nodeptr initnode();
void freenode(nodeptr node);

void _uct(nodeptr node);

#endif /* MCTS_H_ */
