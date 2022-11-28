#include "./mcts.h"

nodeptr initnode() {
        nodeptr node;
        node = (nodeptr) malloc(sizeof(struct node));

        node->wins = 0;
        node->visits = 0;

        return node;
}

void freenode(nodeptr node) {
        for (int i = 0; node->children[i]; ++i) {
                freenode(node->children[i]);
        }

        free(node);
}
