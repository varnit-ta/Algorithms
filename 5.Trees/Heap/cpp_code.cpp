#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void buildHeap(vector<int>& arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

void heapSort(vector<int>& arr) {
    int size = arr.size();
    buildHeap(arr, size);

    cout << "\n====================\n";
    cout << "Original Heap: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    cout << "Sorted Heap: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n====================\n";
}

void insert(vector<int>& arr, int num) {
    cout << "\n====================\n";
    cout << "Previous Heap: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    arr.push_back(num);
    buildHeap(arr, arr.size());

    cout << "After Heap: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n====================\n";
}

void remove(vector<int>& arr, int num) {
    cout << "\n====================\n";
    cout << "Previous Heap: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    int size = arr.size();
    int i = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] == num) {
            break;
        }
    }

    swap(arr[i], arr[size - 1]);
    arr.pop_back();

    buildHeap(arr, arr.size());

    cout << "After Heap: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n====================\n";
}

int main() {
    vector<int> array = {10, 4, 2, 12, 134, 5, 33, 3};

    while (true) {
        cout << "1. Heap Sort\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            vector<int> copy = array;
            heapSort(copy);
        } else if (choice == 2) {
            int num;
            cout << "Enter value to insert in heap: ";
            cin >> num;
            insert(array, num);
        } else if (choice == 3) {
            int num;
            cout << "Enter value to delete from heap: ";
            cin >> num;
            remove(array, num);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid Input\n";
        }
    }

    return 0;
}
