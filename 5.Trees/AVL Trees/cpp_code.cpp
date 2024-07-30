#include <iostream>
#include <algorithm>

class AVLNode {
    /**
     * A node in an AVL tree.
     * 
     * Attributes:
     *     key (int): The key stored in the node.
     *     left (AVLNode*): The left child node.
     *     right (AVLNode*): The right child node.
     *     height (int): The height of the node.
     */
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree {
    /**
     * An AVL tree class with basic AVL tree operations.
     * 
     * Attributes:
     *     root (AVLNode*): The root node of the AVL tree.
     * 
     * Methods:
     *     insert(int key): Inserts a key into the AVL tree.
     *     delete(int key): Deletes a key from the AVL tree.
     *     search(int key): Searches for a key in the AVL tree.
     *     traverse(): Traverses and prints the AVL tree in-order.
     */
private:
    AVLNode* root;

    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insert(AVLNode* node, int key);
    AVLNode* deleteNode(AVLNode* node, int key);
    AVLNode* getMinValueNode(AVLNode* node);
    void inOrder(AVLNode* node);

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int key);
    void deleteNode(int key);
    AVLNode* search(int key);
    void traverse();
};

int AVLTree::getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int AVLTree::getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

AVLNode* AVLTree::insert(AVLNode* node, int key) {
    if (!node) return new AVLNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

AVLNode* AVLTree::deleteNode(AVLNode* node, int key) {
    if (!node) return node;
    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else {
        if (!node->left)
            return node->right;
        if (!node->right)
            return node->left;
        AVLNode* temp = getMinValueNode(node->right);
        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
    }
    if (!node) return node;
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

AVLNode* AVLTree::getMinValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left) current = current->left;
    return current;
}

void AVLTree::inOrder(AVLNode* node) {
    if (node) {
        inOrder(node->left);
        std::cout << node->key << " ";
        inOrder(node->right);
    }
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

void AVLTree::deleteNode(int key) {
    root = deleteNode(root, key);
}

AVLNode* AVLTree::search(int key) {
    AVLNode* current = root;
    while (current) {
        if (current->key == key) return current;
        if (key < current->key) current = current->left;
        else current = current->right;
    }
    return nullptr;
}

void AVLTree::traverse() {
    inOrder(root);
    std::cout << std::endl;
}

// Example usage
int main() {
    AVLTree avl_tree;
    int keys[] = {20, 15, 25, 10, 5, 30, 35};
    for (int key : keys) {
        avl_tree.insert(key);
    }
    std::cout << "AVL Tree (in-order):" << std::endl;
    avl_tree.traverse();
    avl_tree.deleteNode(15);
    std::cout << "AVL Tree after deleting 15 (in-order):" << std::endl;
    avl_tree.traverse();
    AVLNode* found_node = avl_tree.search(25);
    if (found_node) {
        std::cout << "Node with key " << found_node->key << " found." << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }
    return 0;
}
