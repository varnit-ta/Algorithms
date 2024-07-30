#include <iostream>

class Node {
    /**
     * A Node in a doubly linked list.
     * 
     * Attributes:
     *     data (int): The data stored in the node.
     *     next (Node*): The pointer to the next node in the list.
     *     prev (Node*): The pointer to the previous node in the list.
     */
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize a node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
    /**
     * A Doubly Linked List class with basic list operations.
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
     *     displayReverse(): Displays the list from the end to the beginning.
     */
private:
    Node* head;

public:
    // Constructor to initialize an empty doubly linked list
    DoublyLinkedList() {
        head = nullptr;
    }

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
        newNode->prev = lastNode;
    }

    // Adds a node with the given data to the beginning of the list
    void prepend(int data) {
        Node* newNode = new Node(data);
        if (head) {
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
    }

    // Deletes the first node containing the given data
    void deleteNode(int data) {
        Node* currentNode = head;
        while (currentNode) {
            if (currentNode->data == data) {
                if (currentNode->prev) {
                    currentNode->prev->next = currentNode->next;
                }
                if (currentNode->next) {
                    currentNode->next->prev = currentNode->prev;
                }
                if (currentNode == head) {
                    head = currentNode->next;
                }
                delete currentNode;
                return;
            }
            currentNode = currentNode->next;
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
            std::cout << currentNode->data << " <-> ";
            currentNode = currentNode->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Displays the list from the end to the beginning
    void displayReverse() {
        Node* currentNode = head;
        Node* lastNode = nullptr;
        while (currentNode) {
            lastNode = currentNode;
            currentNode = currentNode->next;
        }
        while (lastNode) {
            std::cout << lastNode->data << " <-> ";
            lastNode = lastNode->prev;
        }
        std::cout << "NULL" << std::endl;
    }
};

// Example usage
int main() {
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.display();
    dll.prepend(0);
    dll.display();
    dll.deleteNode(2);
    dll.display();
    dll.displayReverse();
    Node* node = dll.search(3);
    if (node) {
        std::cout << "Node with data " << node->data << " found." << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }

    return 0;
}
