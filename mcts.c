#include "./mcts.h"

nodeptr initnode(int move, nodeptr parent) {
        nodeptr node;
        node = (nodeptr) malloc(sizeof(struct node));

        node->move = move;

        node->wins = 0;
        node->visits = 0;
        if (!parent) { ++node->visits; }

        node->parent = parent;
        node->nbchild = 0;
        for (int i = 0; i < 256; ++i) { node->children[i] = NULL; }

        if (parent) { _uct(node); }

        return node;
}

void addchild(nodeptr parent, nodeptr child) {
        assert(parent->nbchild < 256);
        parent->children[parent->nbchild] = child;
        ++parent->nbchild;
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

int search(NCBoard *position) {
        nodeptr root = initnode(-1, NULL);

        int movelist[9];
        int count = movegen(position, movelist);

        for (int i = 0; i < count; ++i) {
                nodeptr node = initnode(movelist[i], root);
                addchild(root, node);
        }

        for (int i = 0; i < root->nbchild; ++i) {
                nodeptr child = root->children[i];
                printf("child %p uct %f move %d\n",
                       child, child->uct, child->move);
        }

        freenode(root);

        return 0; /* best move */
}
