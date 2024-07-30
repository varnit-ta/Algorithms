# Binary Search Tree (BST)

A Binary Search Tree is a node-based binary tree data structure which has the following properties:

1. The left subtree of a node contains only nodes with keys lesser than the node's key.
2. The right subtree of a node contains only nodes with keys greater than the node's key.
3. The left and right subtree each must also be a binary search tree.

## Key Characteristics

1. Efficient for insertion, deletion, and search operations.
2. Maintains sorted data structure.
3. Allows for fast lookup, addition, and removal of items.

## Advantages

1. Faster than arrays for insertion and deletion.
2. Maintains sorted data without the need for explicit sorting algorithms.
3. Allows for efficient range queries.

## Disadvantages

1. Can become unbalanced, leading to O(n) time complexity for operations.
2. Generally slower than hash tables for lookups.
3. Requires more space than arrays.

## Operations

- Insertion: O(log n) average, O(n) worst case
- Deletion: O(log n) average, O(n) worst case
- Search: O(log n) average, O(n) worst case

## Implementation Notes

- Always check for empty tree conditions.
- Be careful with duplicate keys (decide on a policy: allow or disallow).
- Consider implementing a balanced BST (like AVL or Red-Black tree) for guaranteed O(log n) operations.

## Use Cases

1. Implementing associative arrays
2. Sorting algorithms
3. Priority queues
4. Syntax trees in compilers

## Tips

- Use recursive implementation for simplicity, but be aware of stack overflow for very deep trees.
- Consider iterative implementation for better space efficiency.
- Keep track of the parent node for easier deletion operation.
- Implement a balanced BST variant for performance-critical applications.