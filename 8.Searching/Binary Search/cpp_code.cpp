#include <iostream>
#include <vector>

using namespace std;

bool binary_search(const vector<int>& array, int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x) {
            return true;
        }

        if (array[mid] > x) {
            return binary_search(array, x, low, mid - 1);
        }
        if (array[mid] < x) {
            return binary_search(array, x, mid + 1, high);
        }
    }
    return false;
}

int main() {
    vector<int> arr = {0, 3, 5, 6, 93, 100, 304, 406, 987};
    bool result = binary_search(arr, 5, 0, arr.size() - 1);

    if (result) {
        cout << "Element found." << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
