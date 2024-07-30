# Stack Implementation in Python and C++

This repository contains a simple implementation of the Stack data structure in both Python and C++. The Stack follows the Last In, First Out (LIFO) principle and includes basic operations like push, pop, peek, is_empty, and size.

## Python Implementation

The Python implementation is found in the `stack.py` file. The `Stack` class provides the following methods:

- `push(item)`: Adds an item to the stack.
- `pop()`: Removes and returns the top item from the stack.
- `peek()`: Returns the top item without removing it.
- `is_empty()`: Checks if the stack is empty.
- `size()`: Returns the number of items in the stack.

### Example Usage

```python
from stack import Stack

stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
print(f"Top item is {stack.peek()}")
print(f"Stack size is {stack.size()}")
print(f"Popped item is {stack.pop()}")
print(f"Stack is empty: {stack.is_empty()}")
