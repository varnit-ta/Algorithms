# Doubly Linked List Implementation

This repository contains an implementation of the Doubly Linked List data structure. A doubly linked list is a type of linked list in which each node has two links: one pointing to the next node and another pointing to the previous node.


### Definition

A **doubly linked list** is a linear data structure where each element (or node) contains a pair of links: one link pointing to the next node in the sequence and another link pointing to the previous node. The first node's previous link and the last node's next link point to `null` (or `None` in Python), marking the ends of the list.

### Key Characteristics

1. **Node Structure**:
   - Each node in a doubly linked list consists of three parts:
     - `Data`: Stores the value or information.
     - `Next`: A reference or pointer to the next node in the list.
     - `Prev`: A reference or pointer to the previous node in the list.

2. **Head**:
   - The starting point of the list. It is a pointer/reference to the first node. If the list is empty, the head is set to `null` (or `None`).

3. **Tail** (Optional):
   - A pointer/reference to the last node, which can make certain operations like adding to the end more efficient.

### Basic Operations

1. **Insertion**:
   - **At the Beginning**: A new node is created and its `next` pointer is set to the current head, and the head's `prev` pointer is updated to the new node. The head is then updated to the new node.
   - **At the End**: A new node is created and appended by setting the new node's `prev` pointer to the last node and the last node's `next` pointer to the new node. If a tail pointer is used, the new node is linked directly to the tail and the tail is updated.
   - **At a Specific Position**: The list is traversed to the desired position, and the new node is inserted by adjusting the `next` and `prev` pointers of adjacent nodes.

2. **Deletion**:
   - **From the Beginning**: The head is updated to point to the next node, and the new head's `prev` pointer is set to `null`.
   - **From the End**: The tail's `prev` pointer is updated to point to the new last node, and the new last node's `next` pointer is set to `null`.
   - **From a Specific Position**: The node preceding the one to be deleted is found, and its `next` pointer is updated to skip the deleted node, while the `prev` pointer of the next node is updated to point to the previous node of the deleted node.

3. **Searching**:
   - The list is traversed from the head, comparing each node's data with the target value until the desired node is found or the end of the list is reached.

4. **Traversal**:
   - **Forward Traversal**: Visiting each node in the list starting from the head.
   - **Backward Traversal**: Visiting each node starting from the last node (or tail) and moving towards the head.

### Advantages

- **Bidirectional Navigation**: Unlike singly linked lists, doubly linked lists allow traversal in both forward and backward directions, which can be useful for certain algorithms.
- **Ease of Deletion**: Nodes can be deleted more easily because each node has a reference to both its predecessor and successor.

### Disadvantages

- **Memory Overhead**: Requires more memory per node due to the additional `prev` pointer.
- **Complexity**: Managing the additional pointers increases the complexity of insertion and deletion operations compared to singly linked lists.

### Applications

Doubly linked lists are used in various applications such as:
- Implementing more complex data structures like deques and some variations of heaps.
- Navigation systems where both forward and backward traversal is needed.
- Managing playlists in media players or undo-redo functionality in applications.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
