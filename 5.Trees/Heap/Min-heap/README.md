# Min-Heap Data Structure

This repository contains implementations of a Min-Heap data structure in Python and C++. A Min-Heap is a binary heap where the key at the root node is the minimum among all keys in the heap. The heap property ensures that the smallest element is always at the root.

## Notes on Min-Heap

### Definition

A **Min-Heap** is a complete binary tree where:
- **Heap Property**: The value of each node is less than or equal to the values of its children.
- **Complete Tree Property**: All levels of the tree are fully filled except possibly for the last level, which is filled from left to right.

### Key Operations

1. **Insert**:
   - **Procedure**: Add the new element at the end of the tree (maintaining the complete tree property) and then perform a bubble-up operation to maintain the heap property.

2. **Extract Min**:
   - **Procedure**: Remove the root node (which contains the minimum value), replace it with the last element in the heap, and then perform a heapify operation to restore the heap property.

3. **Get Min**:
   - **Procedure**: Return the value of the root node, which is the minimum element in the heap.

4. **Build Heap**:
   - **Procedure**: Convert an unordered array into a Min-Heap by performing the heapify operation starting from the last non-leaf node up to the root.

5. **Display**:
   - **Procedure**: Print the elements of the heap in their current order.

### Advantages

- **Efficient Minimum Retrieval**: The minimum element can be retrieved in constant time, O(1).
- **Efficient Insertion and Deletion**: Both operations are performed in logarithmic time, O(log n), due to the heap property.

### Disadvantages

-
