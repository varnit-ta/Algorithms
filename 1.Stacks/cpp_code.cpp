#include <iostream>
#include <vector>

class Stack {
    /**
     * A simple Stack class with basic stack operations.
     * 
     * Attributes:
     *     items (std::vector<int>): The vector to store stack elements.
     * 
     * Methods:
     *     push(int item): Pushes an item onto the stack.
     *     pop(): Removes and returns the top item from the stack.
     *     peek(): Returns the top item without removing it.
     *     isEmpty(): Checks if the stack is empty.
     *     size(): Returns the size of the stack.
     */
private:
    std::vector<int> items;

public:
    // Constructor to initialize the stack
    Stack() {}

    // Push an item onto the stack
    void push(int item) {
        items.push_back(item);
    }

    // Pop the top item from the stack
    int pop() {
        if (!isEmpty()) {
            int top = items.back();
            items.pop_back();
            return top;
        }
        return -1; // Indicates an empty stack
    }

    // Peek the top item without removing it
    int peek() {
        if (!isEmpty()) {
            return items.back();
        }
        return -1; // Indicates an empty stack
    }

    // Check if the stack is empty
    bool isEmpty() {
        return items.empty();
    }

    // Return the size of the stack
    int size() {
        return items.size();
    }
};

// Example usage
int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Top item is " << stack.peek() << std::endl;
    std::cout << "Stack size is " << stack.size() << std::endl;
    std::cout << "Popped item is " << stack.pop() << std::endl;
    std::cout << "Stack is empty: " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
