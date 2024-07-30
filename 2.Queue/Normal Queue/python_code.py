class Queue:
    """
    A simple Queue class with basic queue operations.

    Attributes:
        items (list): The list to store queue elements.

    Methods:
        enqueue(item): Adds an item to the queue.
        dequeue(): Removes and returns the front item from the queue.
        front(): Returns the front item without removing it.
        is_empty(): Checks if the queue is empty.
        size(): Returns the size of the queue.
    """

    def __init__(self):
        """Initializes an empty queue."""
        self.items = []

    def enqueue(self, item):
        """Adds an item to the queue."""
        self.items.append(item)

    def dequeue(self):
        """Removes and returns the front item from the queue."""
        if not self.is_empty():
            return self.items.pop(0)
        return None

    def front(self):
        """Returns the front item without removing it."""
        if not self.is_empty():
            return self.items[0]
        return None

    def is_empty(self):
        """Checks if the queue is empty."""
        return len(self.items) == 0

    def size(self):
        """Returns the size of the queue."""
        return len(self.items)

# Example usage
if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    print(f"Front item is {queue.front()}")
    print(f"Queue size is {queue.size()}")
    print(f"Dequeued item is {queue.dequeue()}")
    print(f"Queue is empty: {queue.is_empty()}")
