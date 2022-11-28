#include "./mcts.h"

/*
 * Initialize Node
 *
 * Allocate memory for a new node and set it's members. Nodes represent
 * a possible move, and store how many winning games have been played from
 * the move, how many total games have been played from the move, the parent
 * node (the previously played move), the children nodes (all possible moves
 * after this node's move), and the Upper Confidence bounds applied to Trees
 * which indicates the quality of the move.
 */
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

/*
 * Add Child
 *
 * Append a new child onto the parent node.
 */
void addchild(nodeptr parent, nodeptr child) {
        assert(parent->nbchild < 256);
        parent->children[parent->nbchild] = child;
        ++parent->nbchild;
}

/*
 * Free Node
 *
 * Recursively free all nodes starting at the provided node. Calling this
 * function on the root with free the entire tree.
 */
void freenode(nodeptr node) {
        for (int i = 0; node->children[i]; ++i) {
                freenode(node->children[i]);
        }

        free(node);
}

/*
 * Upper Confidence Bounds Applied to Trees
 *
 * Calculate the UCT of the provided node.
 */
void _uct(nodeptr node) {
        float visits = node->visits + 0.001;
        float ratio = node->wins / visits;
        float explore = C * sqrt(log(node->parent->visits) / visits);

        node->uct = ratio + explore;
}

/*
 * Selection
 *
 * Return any child node that hasn't been visited yet. If all children have,
 * been visited, return the node with the highest UCT.
 */
nodeptr selection(nodeptr node) {
        nodeptr best = node->children[0];

        for (int i = 0; i < node->nbchild; ++i) {
                nodeptr child = node->children[i];

                if (child->visits == 0) { return child; }
                if (child->uct > best->uct) { best = child; }
        }

        return best;
}

/*
 * Search
 *
 * Create all first-layer children from the current position, initiate
 * rollouts, and return the move with the highest UCT.
 */
int search(NCBoard *position) {
        nodeptr root = initnode(-1, NULL);

        int movelist[9];
        int count = movegen(position, movelist);

        for (int i = 0; i < count; ++i) {
                nodeptr node = initnode(movelist[i], root);
                ++node->visits; /* example */
                addchild(root, node);
        }

        /* example */
        root->children[3]->wins = 1;
        _uct(root->children[3]);

        nodeptr best = NULL;
        int pv = 0;
        for (int i = 0; i < root->nbchild; ++i) {
                best = selection(root);
                pv = best->move;
        }

        freenode(root);

        return pv;
}
