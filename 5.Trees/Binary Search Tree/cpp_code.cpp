#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursive(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }
        if (key < root->key) {
            root->left = insertRecursive(root->left, key);
        } else {
            root->right = insertRecursive(root->right, key);
        }
        return root;
    }

    Node* searchRecursive(Node* root, int key) {
        if (root == nullptr || root->key == key) {
            return root;
        }
        if (key < root->key) {
            return searchRecursive(root->left, key);
        }
        return searchRecursive(root->right, key);
    }

    void inorderRecursive(Node* root) {
        if (root) {
            inorderRecursive(root->left);
            std::cout << root->key << " ";
            inorderRecursive(root->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    bool search(int key) {
        return searchRecursive(root, key) != nullptr;
    }

    void inorderTraversal() {
        inorderRecursive(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal:" << std::endl;
    bst.inorderTraversal();  // Output: 20 30 40 50 60 70 80

    std::cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 90: " << (bst.search(90) ? "Found" : "Not Found") << std::endl;

    return 0;
}