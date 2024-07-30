# Normal Queue Implementation in Python and C++

This repository contains a simple implementation of the Normal Queue data structure in both Python and C++. A queue is a linear data structure that follows the First In, First Out (FIFO) principle, meaning the first element added is the first to be removed.

## Python Implementation

The Python implementation is found in the `queue.py` file. The `Queue` class provides the following methods:

- `enqueue(item)`: Adds an item to the queue.
- `dequeue()`: Removes and returns the front item from the queue.
- `front()`: Returns the front item without removing it.
- `is_empty()`: Checks if the queue is empty.
- `size()`: Returns the number of items in the queue.

### Example Usage

```python
queue = Queue()
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
print(f"Front item is {queue.front()}")
print(f"Queue size is {queue.size()}")
print(f"Dequeued item is {queue.dequeue()}")
print(f"Queue is empty: {queue.is_empty()}")
