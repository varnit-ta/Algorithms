#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap {
    /**
     * A class representing a Min-Heap data structure.
     * 
     * Attributes:
     *     heap (std::vector<int>): The underlying vector storing the heap elements.
     * 
     * Methods:
     *     insert(int value): Inserts a value into the Min-Heap.
     *     extractMin(): Removes and returns the minimum value from the Min-Heap.
     *     getMin(): Returns the minimum value without removing it.
     *     heapify(int index): Maintains the Min-Heap property starting from a given index.
     *     buildHeap(std::vector<int> array): Builds a Min-Heap from an array.
     *     display(): Prints the current state of the heap.
     */
private:
    std::vector<int> heap;

    void bubbleUp(int index);
    void heapify(int index);

public:
    MinHeap() {}

    void insert(int value);
    int extractMin();
    int getMin();
    void buildHeap(const std::vector<int>& array);
    void display();
};

void MinHeap::bubbleUp(int index) {
    int parentIndex = (index - 1) / 2;
    if (index > 0 && heap[index] < heap[parentIndex]) {
        std::swap(heap[index], heap[parentIndex]);
        bubbleUp(parentIndex);
    }
}

void MinHeap::heapify(int index) {
    int smallest = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[smallest])
        smallest = leftChildIndex;

    if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallest])
        smallest = rightChildIndex;

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapify(smallest);
    }
}

void MinHeap::insert(int value) {
    heap.push_back(value);
    bubbleUp(heap.size() - 1);
}

int MinHeap::extractMin() {
    if (heap.empty())
        throw std::runtime_error("Extract from an empty heap");
    if (heap.size() == 1) {
        int minValue = heap.back();
        heap.pop_back();
        return minValue;
    }
    int minValue = heap.front();
    heap[0] = heap.back();
    heap.pop_back();
    heapify(0);
    return minValue;
}

int MinHeap::getMin() {
    if (heap.empty())
        throw std::runtime_error("Heap is empty");
    return heap.front();
}

void MinHeap::buildHeap(const std::vector<int>& array) {
    heap = array;
    for (int i = heap.size() / 2 - 1; i >= 0; --i)
        heapify(i);
}

void MinHeap::display() {
    for (int value : heap)
        std::cout << value << " ";
    std::cout << std::endl;
}

// Example usage
int main() {
    MinHeap minHeap;
    std::vector<int> array = {5, 3, 8, 1, 2, 7};
    minHeap.buildHeap(array);
    std::cout << "Heap after building from array:" << std::endl;
    minHeap.display();
    minHeap.insert(0);
    std::cout << "Heap after inserting 0:" << std::endl;
    minHeap.display();
    std::cout << "Extracted min value: " << minHeap.extractMin() << std::endl;
    std::cout << "Heap after extracting min value:" << std::endl;
    minHeap.display();
    std::cout << "Current min value: " << minHeap.getMin() << std::endl;
    return 0;
}
