#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[i] < heap[left]) {
        largest = left;
    }

    if (right < n && heap[largest] < heap[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void heapSort(vector<int>& heap) {
    int n = heap.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(heap, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(heap[i], heap[0]);
        heapify(heap, i, 0);
    }
}

int main() {
    vector<int> heap = {21, 0, 84, 2, 5, 3};

    cout << "Original Heap: ";
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;

    heapSort(heap);

    cout << "Sorted Heap: ";
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
