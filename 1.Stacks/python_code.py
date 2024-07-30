class Stack:
    """
    A simple Stack class with basic stack operations.

    Attributes:
        items (list): The list to store stack elements.

    Methods:
        push(item): Pushes an item onto the stack.
        pop(): Removes and returns the top item from the stack.
        peek(): Returns the top item without removing it.
        is_empty(): Checks if the stack is empty.
        size(): Returns the size of the stack.
    """

    def __init__(self):
        """Initializes an empty stack."""
        self.items = []

    def push(self, item):
        """Pushes an item onto the stack."""
        self.items.append(item)

    def pop(self):
        """Removes and returns the top item from the stack."""
        if not self.is_empty():
            return self.items.pop()
        return None

    def peek(self):
        """Returns the top item without removing it."""
        if not self.is_empty():
            return self.items[-1]
        return None

    def is_empty(self):
        """Checks if the stack is empty."""
        return len(self.items) == 0

    def size(self):
        """Returns the size of the stack."""
        return len(self.items)

# Example usage
if __name__ == "__main__":
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    print(f"Top item is {stack.peek()}")
    print(f"Stack size is {stack.size()}")
    print(f"Popped item is {stack.pop()}")
    print(f"Stack is empty: {stack.is_empty()}")
