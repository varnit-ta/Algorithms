#include <iostream>

using namespace std;

// Node definition
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Function prototypes
Node* insert(Node* root, int key);
Node* remove(Node* root, int key);
Node* search(Node* root, int key);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
Node* minValueNode(Node* node);

// Function implementations
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* remove(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key) {
        root->left = remove(root->left, key);
    } else if (key > root->key) {
        root->right = remove(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = remove(root->right, temp->key);
    }
    return root;
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Example usage
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal:" << endl;
    inorder(root);
    cout << endl;

    cout << "Preorder traversal:" << endl;
    preorder(root);
    cout << endl;

    cout << "Postorder traversal:" << endl;
    postorder(root);
    cout << endl;

    cout << "Search for 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search for 90: " << (search(root, 90) ? "Found" : "Not Found") << endl;

    root = remove(root, 70);
    cout << "Inorder traversal after removing 70:" << endl;
    inorder(root);
    cout << endl;

    return 0;
}
