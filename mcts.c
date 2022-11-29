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

        node->parent = parent;
        node->nbchild = 0;
        for (int i = 0; i < 9; ++i) { node->children[i] = NULL; }

        return node;
}

/*
 * Add Child
 *
 * Append a new child onto the parent node.
 */
void addchild(nodeptr parent, nodeptr child) {
        assert(parent->nbchild < 9);
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
        for (int i = 0; i < node->nbchild; ++i) {
                freenode(node->children[i]);
        }

        free(node);
}

/*
 * Upper Confidence Bounds Applied to Trees
 *
 * Calculate the UCT of the provided node.
 */
float _uct(nodeptr node) {
        float visits = node->visits + 0.001;
        float ratio = node->wins / visits;
        float explore = C * sqrt(log(node->parent->visits) / visits);

        return ratio + explore;
}

/*
 * Selection
 *
 * Return any child node that hasn't been visited yet. If all children have,
 * been visited, return the node with the highest UCT.
 */
nodeptr selection(nodeptr node) {
        nodeptr child;
        float max = 0;

        for (int i = 0; i < node->nbchild; ++i) {
                nodeptr curr = node->children[i];

                if (curr->visits == 0) { return curr; }

                float uct = _uct(curr);
                if (uct > max) {
                        max = uct;
                        child = curr;
                }
        }

        return child;
}

/*
 * Expansion
 *
 * Create all child nodes for the provided nodes.
 */
void expansion(NCBoard *position, nodeptr node) {
        int movelist[9];
        int count = movegen(position, movelist);
        for (int i = 0; i < count; ++i) {
                nodeptr child = initnode(movelist[i], node);
                addchild(node, child);
        }
}

/*
 * Rollout
 *
 * Simulate a game until a terminal node is reached and return the result.
 */
int rollout(NCBoard *position, nodeptr node) {
        if (gameover(position)) { return evaluate(position); }

        play(position, node->move);

        if (node->nbchild == 0) { expansion(position, node); }

        ++node->visits;
        int result = -rollout(position, selection(node));
        if (result == 0) { result = rand() % 2 == 0 ? 1 : -1; }
        if (result == 1) { ++node->wins; }

        unmake(position);
        
        return result;
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
                addchild(root, node);
        }

        for (int t = 0; t < 10000; ++t) {
                ++root->visits;
                nodeptr node = selection(root);
                rollout(position, node);
        }

        float best = 0;
        int pv;
        for (int i = 0; i < root->nbchild; ++i) {
                nodeptr child = root->children[i];
                float uct = _uct(child);
                if (uct > best) {
                        best = uct;
                        pv = child->move;
                }
        }

        freenode(root);

        return pv;
}
