#include <iostream>

struct Node {
    /**
     * A Node in a singly linked list.
     * 
     * Attributes:
     *     data (int): The data stored in the node.
     *     next (Node*): The pointer to the next node in the list.
     */
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int data) : data(data), next(nullptr) {}
};

struct SinglyLinkedList {
    /**
     * A Singly Linked List struct with basic list operations.
     * 
     * Attributes:
     *     head (Node*): The head node of the list.
     * 
     * Methods:
     *     append(int data): Adds a node with the given data to the end of the list.
     *     prepend(int data): Adds a node with the given data to the beginning of the list.
     *     deleteNode(int data): Deletes the first node containing the given data.
     *     search(int data): Searches for a node containing the given data.
     *     display(): Displays the list as a sequence of data elements.
     */
    Node* head;

    // Constructor to initialize an empty singly linked list
    SinglyLinkedList() : head(nullptr) {}

    // Adds a node with the given data to the end of the list
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* lastNode = head;
        while (lastNode->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    // Adds a node with the given data to the beginning of the list
    void prepend(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Deletes the first node containing the given data
    void deleteNode(int data) {
        if (!head) {
            return;
        }
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* currentNode = head;
        while (currentNode->next && currentNode->next->data != data) {
            currentNode = currentNode->next;
        }
        if (currentNode->next) {
            Node* temp = currentNode->next;
            currentNode->next = currentNode->next->next;
            delete temp;
        }
    }

    // Searches for a node containing the given data
    Node* search(int data) {
        Node* currentNode = head;
        while (currentNode) {
            if (currentNode->data == data) {
                return currentNode;
            }
            currentNode = currentNode->next;
        }
        return nullptr;
    }

    // Displays the list as a sequence of data elements
    void display() {
        Node* currentNode = head;
        while (currentNode) {
            std::cout << currentNode->data << " -> ";
            currentNode = currentNode->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

// Example usage
int main() {
    SinglyLinkedList sll;
    sll.append(1);
    sll.append(2);
    sll.append(3);
    sll.display();
    sll.prepend(0);
    sll.display();
    sll.deleteNode(2);
    sll.display();
    Node* node = sll.search(3);
    if (node) {
        std::cout << "Node with data " << node->data << " found." << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }

    return 0;
}
