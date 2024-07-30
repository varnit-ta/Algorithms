# Singly Linked List Implementation

This repository contains an implementation of the Singly Linked List data structure. A singly linked list is a linear data structure that consists of nodes, each containing a data element and a reference (or link) to the next node in the sequence.


### Definition

A **singly linked list** is a type of linked list in which each node points to the next node in the sequence, and the last node points to `null` (or `None` in Python). The list contains a head pointer, which points to the first node, and may also have a tail pointer pointing to the last node.

### Key Characteristics

1. **Node Structure**:
   - Each node in a singly linked list consists of two parts:
     - `Data`: Stores the value or information.
     - `Next`: A reference or pointer to the next node in the list.

2. **Head**:
   - The starting point of the list. It is a pointer/reference to the first node. If the list is empty, the head is set to `null` (or `None`).

3. **Tail** (Optional):
   - A pointer/reference to the last node, sometimes maintained to make certain operations more efficient (like adding to the end of the list).

### Basic Operations

1. **Insertion**:
   - **At the Beginning**: A new node is created and its `next` pointer is set to the current head. The head is then updated to the new node.
   - **At the End**: A new node is created and appended by traversing the list to the last node and setting its `next` pointer to the new node. If a tail pointer is used, the new node is linked directly to the tail and the tail is updated.
   - **At a Specific Position**: The list is traversed to the desired position, and the new node is inserted by adjusting the `next` pointers accordingly.

2. **Deletion**:
   - **From the Beginning**: The head is updated to point to the next node, effectively removing the first node.
   - **From the End**: The list is traversed to find the second-to-last node, which is then updated to point to `null`, removing the last node.
   - **From a Specific Position**: The node preceding the one to be deleted is found, and its `next` pointer is updated to skip the deleted node and point to the next one.

3. **Searching**:
   - The list is traversed from the head, comparing each node's data with the target value until the desired node is found or the end of the list is reached.

4. **Traversal**:
   - Visiting each node in the list starting from the head, often used to display the list contents or perform operations on each node.

### Advantages

- **Dynamic Size**: Unlike arrays, singly linked lists do not need a predefined size, and they can grow or shrink as needed.
- **Ease of Insertion/Deletion**: Adding or removing nodes, especially at the beginning, is efficient (O(1) time complexity) compared to arrays where shifting elements might be necessary.

### Disadvantages

- **No Random Access**: Accessing a specific element requires traversal from the head, resulting in O(n) time complexity for finding an element.
- **Memory Overhead**: Additional memory is required for storing the `next` pointers in each node.
- **Inefficient Operations**: Operations like searching and accessing elements are slower compared to arrays due to the lack of direct indexing.

### Applications

Singly linked lists are used in various applications such as:
- Implementing stacks and queues.
- Managing memory by implementing dynamic data structures.
- Real-time applications where data can change frequently.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
