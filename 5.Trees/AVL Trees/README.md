# AVL Tree Implementation

This repository contains an implementation of the AVL tree data structure. An AVL tree is a self-balancing binary search tree where the difference in heights between the left and right subtrees of any node is no more than one.

### Definition

An **AVL Tree** (named after its inventors Adelson-Velsky and Landis) is a self-balancing binary search tree. It maintains the following properties:
- **Binary Search Tree Property**: For any node, all keys in the left subtree are smaller, and all keys in the right subtree are larger.
- **Balance Factor**: For every node in the tree, the height difference between the left and right subtrees (balance factor) is at most 1.

### Key Characteristics

1. **Node Structure**:
   - Each node contains:
     - `key`: The value stored in the node.
     - `left`: A pointer to the left child node.
     - `right`: A pointer to the right child node.
     - `height`: The height of the node, which helps in maintaining balance.

2. **Root**:
   - The topmost node in the tree. It is the starting point for all operations.

3. **Height**:
   - The height of a node is defined as the number of edges on the longest path from the node to a leaf. 

### Basic Operations

1. **Insertion**:
   - **Into the Tree**: The key is inserted in the correct position based on binary search tree properties. After insertion, the tree is rebalanced using rotations if necessary to maintain the AVL property.

2. **Deletion**:
   - **From the Tree**: The key is removed from the correct position based on binary search tree properties. After deletion, the tree is rebalanced to ensure it remains an AVL tree.

3. **Search**:
   - **In the Tree**: The tree is traversed starting from the root, comparing the target key with the current node’s key, and moving to the left or right child as needed.

4. **Traversal**:
   - **In-Order Traversal**: Visiting all nodes in ascending order by recursively traversing the left subtree, visiting the node, and then traversing the right subtree.

### Advantages

- **Self-Balancing**: Ensures that the height of the tree is always logarithmic relative to the number of nodes, which guarantees O(log n) time complexity for search, insertion, and deletion operations.
- **Efficient Operations**: Provides faster operations compared to unbalanced binary search trees.

### Disadvantages

- **Complex Rotations**: The need for rotations to maintain balance adds complexity to insertion and deletion operations.
- **Additional Overhead**: Maintaining height and balance factors requires additional memory and processing.

### Applications

AVL trees are used in various applications such as:
- **Database Indexing**: To maintain balanced indexes for efficient data retrieval.
- **Memory Management**: In scenarios where frequent insertions and deletions occur and a balanced structure is necessary.
- **Operating Systems**: For managing processes and tasks where efficient balancing and searching are crucial.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
