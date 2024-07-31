#include <iostream>
#include <queue>

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
Node* search(Node* root, int key);
void levelOrder(Node* root);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);

// Function implementations
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == nullptr) {
            temp->left = new Node(key);
            return root;
        } else {
            q.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = new Node(key);
            return root;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

Node* search(Node* root, int key) {
    if (root == nullptr) return nullptr;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->key == key) {
            return temp;
        }

        if (temp->left) {
            q.push(temp->left);
        }

        if (temp->right) {
            q.push(temp->right);
        }
    }
    return nullptr;
}

void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->key << " ";

        if (temp->left) {
            q.push(temp->left);
        }

        if (temp->right) {
            q.push(temp->right);
        }
    }
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

// Example usage
int main() {
    Node* root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    cout << "Level order traversal:" << endl;
    levelOrder(root);
    cout << endl;

    cout << "Inorder traversal:" << endl;
    inorder(root);
    cout << endl;

    cout << "Preorder traversal:" << endl;
    preorder(root);
    cout << endl;

    cout << "Postorder traversal:" << endl;
    postorder(root);
    cout << endl;

    cout << "Search for 4: " << (search(root, 4) ? "Found" : "Not Found") << endl;
    cout << "Search for 10: " << (search(root, 10) ? "Found" : "Not Found") << endl;

    return 0;
}
