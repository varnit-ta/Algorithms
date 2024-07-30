#include <iostream>
#include <vector>

class Queue {
    /**
     * A simple Queue class with basic queue operations.
     * 
     * Attributes:
     *     items (std::vector<int>): The vector to store queue elements.
     * 
     * Methods:
     *     enqueue(int item): Adds an item to the queue.
     *     dequeue(): Removes and returns the front item from the queue.
     *     front(): Returns the front item without removing it.
     *     isEmpty(): Checks if the queue is empty.
     *     size(): Returns the size of the queue.
     */
private:
    std::vector<int> items;

public:
    // Constructor to initialize the queue
    Queue() {}

    // Adds an item to the queue
    void enqueue(int item) {
        items.push_back(item);
    }

    // Removes and returns the front item from the queue
    int dequeue() {
        if (!isEmpty()) {
            int front = items.front();
            items.erase(items.begin());
            return front;
        }
        return -1; // Indicates an empty queue
    }

    // Returns the front item without removing it
    int front() {
        if (!isEmpty()) {
            return items.front();
        }
        return -1; // Indicates an empty queue
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return items.empty();
    }

    // Returns the size of the queue
    int size() {
        return items.size();
    }
};

// Example usage
int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Front item is " << queue.front() << std::endl;
    std::cout << "Queue size is " << queue.size() << std::endl;
    std::cout << "Dequeued item is " << queue.dequeue() << std::endl;
    std::cout << "Queue is empty: " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
