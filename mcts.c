#include "./mcts.h"

nodeptr initnode(nodeptr parent) {
        nodeptr node;
        node = (nodeptr) malloc(sizeof(struct node));

        node->wins = 0;
        node->visits = 0;
        if (!parent) { ++node->visits; }

        node->parent = parent;
        for (int i = 0; i < 256; ++i) { node->children[i] = NULL; }

        if (parent) { _uct(node); }

        return node;
}

void freenode(nodeptr node) {
        for (int i = 0; node->children[i]; ++i) {
                freenode(node->children[i]);
        }

        free(node);
}

void _uct(nodeptr node) {
        float visits = node->visits + 0.001;
        float ratio = node->wins / visits;
        float explore = C * sqrt(log(node->parent->visits) / visits);

        node->uct = ratio + explore;
}
