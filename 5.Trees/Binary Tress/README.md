# B-Tree Implementation

This repository contains an implementation of the B-tree data structure. A B-tree is a balanced tree data structure that maintains sorted data and allows for efficient insertion, deletion, and search operations.

### Definition

A **B-tree** is a self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time. It is characterized by the following:
- **Nodes**: Each node can contain multiple keys and has multiple children.
- **Properties**:
  - Every node has at most `2t - 1` keys and at least `t - 1` keys (except the root, which can have fewer).
  - Each node has at most `2t` children and at least `t` children (except the root).

### Key Characteristics

1. **Node Structure**:
   - Each node contains:
     - `Keys`: Sorted keys in the node.
     - `Children`: References to child nodes.
     - `IsLeaf`: A flag indicating if the node is a leaf.

2. **Root**:
   - The topmost node in the tree. It is the starting point for all operations.

3. **Degree (t)**:
   - The minimum degree `t` of the B-tree determines the maximum and minimum number of keys a node can have and the number of children.

### Basic Operations

1. **Insertion**:
   - **Into a Full Node**: If the root node is full, a new root is created, and the old root is split. The new root is then inserted into the appropriate child node.
   - **Into a Non-Full Node**: The key is inserted into the correct position in the node. If necessary, children nodes are adjusted accordingly.

2. **Deletion**:
   - **From a Node**: Keys are removed from a node, and if the node becomes underflowed (i.e., has fewer than `t - 1` keys), it is rebalanced by borrowing a key from a sibling or merging with a sibling.

3. **Search**:
   - **In a Node**: Keys are compared with the search key. Depending on the result, the search continues in the appropriate child node.

4. **Traversal**:
   - **In-Order Traversal**: Visiting all nodes in sorted order by recursively traversing each child node.

### Advantages

- **Balanced Tree**: The B-tree is always balanced, ensuring that all leaf nodes are at the same depth, which guarantees logarithmic time complexity for operations.
- **Efficient Disk Access**: B-trees are commonly used in databases and file systems where they reduce the number of disk accesses required.

### Disadvantages

- **Complex Implementation**: Due to the need for node splitting and merging, B-trees can be more complex to implement compared to simpler data structures.

### Applications

B-trees are widely used in applications such as:
- **Databases**: To manage large datasets and ensure efficient query operations.
- **File Systems**: To store and manage directories and files efficiently.
- **Indexing**: To maintain indexes in data storage systems for fast search and retrieval.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
