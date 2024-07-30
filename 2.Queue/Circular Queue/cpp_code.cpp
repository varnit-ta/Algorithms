#include <iostream>
#include <vector>

class CircularQueue {
    /**
     * A CircularQueue class with basic queue operations.
     * 
     * Attributes:
     *     max_size (int): The maximum size of the circular queue.
     *     items (std::vector<int>): The vector to store queue elements.
     *     front (int): The index of the front element.
     *     rear (int): The index of the rear element.
     * 
     * Methods:
     *     enqueue(int item): Adds an item to the queue.
     *     dequeue(): Removes and returns the front item from the queue.
     *     isEmpty(): Checks if the queue is empty.
     *     isFull(): Checks if the queue is full.
     *     front(): Returns the front item without removing it.
     *     size(): Returns the size of the queue.
     */
private:
    int max_size;
    std::vector<int> items;
    int front;
    int rear;

public:
    // Constructor to initialize the circular queue with a given max size
    CircularQueue(int maxSize) : max_size(maxSize), items(maxSize, -1), front(-1), rear(-1) {}

    // Adds an item to the queue
    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % max_size;
        items[rear] = item;
    }

    // Removes and returns the front item from the queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1; // Indicates an empty queue
        }
        int result = items[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % max_size;
        }
        return result;
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Checks if the queue is full
    bool isFull() {
        return (rear + 1) % max_size == front;
    }

    // Returns the front item without removing it
    int getFront() {
        if (!isEmpty()) {
            return items[front];
        }
        return -1; // Indicates an empty queue
    }

    // Returns the size of the queue
    int size() {
        if (isEmpty()) {
            return 0;
        }
        if (rear >= front) {
            return rear - front + 1;
        }
        return max_size - front + rear + 1;
    }
};

// Example usage
int main() {
    CircularQueue cqueue(3);
    cqueue.enqueue(1);
    cqueue.enqueue(2);
    cqueue.enqueue(3);
    std::cout << "Circular Queue is full: " << (cqueue.isFull() ? "Yes" : "No") << std::endl;
    std::cout << "Front item in circular queue is " << cqueue.getFront() << std::endl;
    std::cout << "Circular Queue size is " << cqueue.size() << std::endl;
    std::cout << "Dequeued item from circular queue is " << cqueue.dequeue() << std::endl;
    std::cout << "Circular Queue is empty: " << (cqueue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
