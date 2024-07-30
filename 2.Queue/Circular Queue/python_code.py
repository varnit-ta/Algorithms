class CircularQueue:
    """
    A CircularQueue class with basic queue operations.

    Attributes:
        max_size (int): The maximum size of the circular queue.
        items (list): The list to store queue elements.
        front (int): The index of the front element.
        rear (int): The index of the rear element.

    Methods:
        enqueue(item): Adds an item to the queue.
        dequeue(): Removes and returns the front item from the queue.
        is_empty(): Checks if the queue is empty.
        is_full(): Checks if the queue is full.
        front_item(): Returns the front item without removing it.
        size(): Returns the size of the queue.
    """

    def __init__(self, max_size):
        """Initializes an empty circular queue with a given max size."""
        self.max_size = max_size
        self.items = [None] * max_size
        self.front = -1
        self.rear = -1

    def enqueue(self, item):
        """Adds an item to the queue."""
        if self.is_full():
            return "Queue is full"
        if self.front == -1:
            self.front = 0
        self.rear = (self.rear + 1) % self.max_size
        self.items[self.rear] = item

    def dequeue(self):
        """Removes and returns the front item from the queue."""
        if self.is_empty():
            return "Queue is empty"
        result = self.items[self.front]
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = (self.front + 1) % self.max_size
        return result

    def is_empty(self):
        """Checks if the queue is empty."""
        return self.front == -1

    def is_full(self):
        """Checks if the queue is full."""
        return (self.rear + 1) % self.max_size == self.front

    def front_item(self):
        """Returns the front item without removing it."""
        if not self.is_empty():
            return self.items[self.front]
        return None

    def size(self):
        """Returns the size of the queue."""
        if self.is_empty():
            return 0
        if self.rear >= self.front:
            return self.rear - self.front + 1
        return self.max_size - self.front + self.rear + 1

# Example usage
if __name__ == "__main__":
    cqueue = CircularQueue(3)
    cqueue.enqueue(1)
    cqueue.enqueue(2)
    cqueue.enqueue(3)
    print(f"Circular Queue is full: {cqueue.is_full()}")
    print(f"Front item in circular queue is {cqueue.front_item()}")
    print(f"Circular Queue size is {cqueue.size()}")
    print(f"Dequeued item from circular queue is {cqueue.dequeue()}")
    print(f"Circular Queue is empty: {cqueue.is_empty()}")