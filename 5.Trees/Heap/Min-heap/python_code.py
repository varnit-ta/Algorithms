class MinHeap:
    """
    A class representing a Min-Heap data structure.

    Attributes:
        heap (list): The underlying list storing the heap elements.

    Methods:
        insert(value): Inserts a value into the Min-Heap.
        extract_min(): Removes and returns the minimum value from the Min-Heap.
        get_min(): Returns the minimum value without removing it.
        heapify(index): Maintains the Min-Heap property starting from a given index.
        build_heap(array): Builds a Min-Heap from an array.
        display(): Prints the current state of the heap.
    """
    def __init__(self):
        self.heap = []

    def insert(self, value):
        """Inserts a value into the Min-Heap and maintains the heap property."""
        self.heap.append(value)
        self._bubble_up(len(self.heap) - 1)

    def extract_min(self):
        """Removes and returns the minimum value from the Min-Heap."""
        if len(self.heap) == 0:
            raise IndexError("Extract from an empty heap")
        if len(self.heap) == 1:
            return self.heap.pop()
        min_value = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._heapify(0)
        return min_value

    def get_min(self):
        """Returns the minimum value in the Min-Heap without removing it."""
        if len(self.heap) == 0:
            raise IndexError("Heap is empty")
        return self.heap[0]

    def _bubble_up(self, index):
        """Maintains the Min-Heap property by bubbling up the value at the given index."""
        parent_index = (index - 1) // 2
        if index > 0 and self.heap[index] < self.heap[parent_index]:
            self.heap[index], self.heap[parent_index] = self.heap[parent_index], self.heap[index]
            self._bubble_up(parent_index)

    def _heapify(self, index):
        """Maintains the Min-Heap property by heapifying the value at the given index."""
        smallest = index
        left_child_index = 2 * index + 1
        right_child_index = 2 * index + 2

        if (left_child_index < len(self.heap) and
                self.heap[left_child_index] < self.heap[smallest]):
            smallest = left_child_index

        if (right_child_index < len(self.heap) and
                self.heap[right_child_index] < self.heap[smallest]):
            smallest = right_child_index

        if smallest != index:
            self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
            self._heapify(smallest)

    def build_heap(self, array):
        """Builds a Min-Heap from the given array."""
        self.heap = array
        for i in range(len(self.heap) // 2 - 1, -1, -1):
            self._heapify(i)

    def display(self):
        """Prints the current state of the heap."""
        print(self.heap)

# Example usage
if __name__ == "__main__":
    min_heap = MinHeap()
    min_heap.build_heap([5, 3, 8, 1, 2, 7])
    print("Heap after building from array:")
    min_heap.display()
    min_heap.insert(0)
    print("Heap after inserting 0:")
    min_heap.display()
    print("Extracted min value:", min_heap.extract_min())
    print("Heap after extracting min value:")
    min_heap.display()
    print("Current min value:", min_heap.get_min())
