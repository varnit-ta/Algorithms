#include <iostream>
#include <vector>

class BTreeNode {
    /**
     * A node in a B-tree.
     * 
     * Attributes:
     *     t (int): Minimum degree of the B-tree.
     *     isLeaf (bool): A flag indicating if the node is a leaf.
     *     keys (std::vector<int>): A list of keys in the node.
     *     children (std::vector<BTreeNode*>): A list of children nodes.
     */
public:
    int t;
    bool isLeaf;
    std::vector<int> keys;
    std::vector<BTreeNode*> children;

    BTreeNode(int t, bool isLeaf) {
        this->t = t;
        this->isLeaf = isLeaf;
    }

    void traverse(int level = 0) {
        /** Traverses and prints the B-tree. */
        std::cout << "Level " << level << " : ";
        for (int key : keys) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
        if (!isLeaf) {
            for (BTreeNode* child : children) {
                child->traverse(level + 1);
            }
        }
    }
};

class BTree {
    /**
     * A B-tree class with basic B-tree operations.
     * 
     * Attributes:
     *     root (BTreeNode*): The root node of the B-tree.
     * 
     * Methods:
     *     insert(int key): Inserts a key into the B-tree.
     *     traverse(): Traverses and prints the B-tree.
     */
private:
    BTreeNode* root;
    int t;

    void splitChild(BTreeNode* parent, int i);
    void insertNonFull(BTreeNode* node, int key);

public:
    BTree(int t) {
        this->t = t;
        root = new BTreeNode(t, true);
    }

    void insert(int key);
    void traverse() {
        root->traverse();
    }
};

void BTree::splitChild(BTreeNode* parent, int i) {
    /** Splits the child of a node. */
    BTreeNode* y = parent->children[i];
    BTreeNode* z = new BTreeNode(y->t, y->isLeaf);
    parent->children.insert(parent->children.begin() + i + 1, z);
    parent->keys.insert(parent->keys.begin() + i, y->keys[y->t - 1]);
    z->keys.assign(y->keys.begin() + y->t, y->keys.end());
    y->keys.resize(y->t - 1);
    if (!y->isLeaf) {
        z->children.assign(y->children.begin() + y->t, y->children.end());
        y->children.resize(y->t);
    }
}

void BTree::insertNonFull(BTreeNode* node, int key) {
    /** Inserts a key into a node that is not full. */
    int i = node->keys.size() - 1;
    if (node->isLeaf) {
        node->keys.push_back(0);
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;
        if (node->children[i]->keys.size() == (2 * t - 1)) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

void BTree::insert(int key) {
    /** Inserts a key into the B-tree. */
    BTreeNode* r = root;
    if (r->keys.size() == (2 * t - 1)) {
        BTreeNode* s = new BTreeNode(t, false);
        root = s;
        s->children.push_back(r);
        splitChild(s, 0);
        insertNonFull(s, key);
    } else {
        insertNonFull(r, key);
    }
}

// Example usage
int main() {
    BTree btree(2);  // Create a B-tree with minimum degree 2
    std::vector<int> keys = {10, 20, 5, 6, 15, 30, 25, 40, 50, 35};
    for (int key : keys) {
        btree.insert(key);
    }
    btree.traverse();
    return 0;
}
