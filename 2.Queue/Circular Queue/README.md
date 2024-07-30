# Circular Queue Implementation in Python and C++

This repository contains an implementation of the Circular Queue data structure in both Python and C++. A circular queue is a linear data structure that follows the First In, First Out (FIFO) principle, where the last position is connected back to the first position to make a circle.

## Python Implementation

The Python implementation is found in the `circular_queue.py` file. The `CircularQueue` class provides the following methods:

- `enqueue(item)`: Adds an item to the queue.
- `dequeue()`: Removes and returns the front item from the queue.
- `front_item()`: Returns the front item without removing it.
- `is_empty()`: Checks if the queue is empty.
- `is_full()`: Checks if the queue is full.
- `size()`: Returns the number of items in the queue.

### Example Usage

```python
cqueue = CircularQueue(3)
cqueue.enqueue(1)
cqueue.enqueue(2)
cqueue.enqueue(3)
print(f"Circular Queue is full: {cqueue.is_full()}")
print(f"Front item in circular queue is {cqueue.front_item()}")
print(f"Circular Queue size is {cqueue.size()}")
print(f"Dequeued item from circular queue is {cqueue.dequeue()}")
print(f"Circular Queue is empty: {cqueue.is_empty()}")
