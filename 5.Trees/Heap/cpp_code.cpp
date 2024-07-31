#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int i) {
        int p = parent(i);
        if (i > 0 && heap[i] > heap[p]) {
            swap(heap[i], heap[p]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        if (right < heap.size() && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            return -1;  // Or throw an exception
        }
        if (heap.size() == 1) {
            int max = heap[0];
            heap.pop_back();
            return max;
        }

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return max;
    }

    int getMax() {
        if (!heap.empty()) {
            return heap[0];
        }
        return -1;  // Or throw an exception
    }
};

int main() {
    MaxHeap heap;
    heap.insert(4);
    heap.insert(7);
    heap.insert(3);
    heap.insert(9);
    heap.insert(1);

    std::cout << "Max element: " << heap.getMax() << std::endl;  // Output: 9
    std::cout << "Extracted max: " << heap.extractMax() << std::endl;  // Output: 9
    std::cout << "New max element: " << heap.getMax() << std::endl;  // Output: 7

    return 0;
}