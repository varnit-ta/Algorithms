#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}
    
    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            new_node->next = head;
        } else {
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = new_node;
            new_node->next = head;
        }
    }
    
    void display() {
        if (!head) return;
        Node* curr = head;
        do {
            std::cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.append(1);
    cll.append(2);
    cll.append(3);
    cll.display();  // Output: 1 2 3
    return 0;
}