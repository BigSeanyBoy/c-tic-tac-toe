#ifndef MCTS_H_
#define MCTS_H_

#include <stdlib.h>
#include <stdio.h>

#define C 2

typedef struct node{
        int wins;
        int visits;
        struct node *children[256];
} * nodeptr;

nodeptr initnode();
void freenode(nodeptr node);

#endif /* MCTS_H_ */
