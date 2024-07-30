class AVLNode:
    """
    A node in an AVL tree.

    Attributes:
        key (int): The key stored in the node.
        left (AVLNode): The left child node.
        right (AVLNode): The right child node.
        height (int): The height of the node.
    """
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    """
    An AVL tree class with basic AVL tree operations.

    Attributes:
        root (AVLNode): The root node of the AVL tree.

    Methods:
        insert(key): Inserts a key into the AVL tree.
        delete(key): Deletes a key from the AVL tree.
        search(key): Searches for a key in the AVL tree.
        traverse(): Traverses and prints the AVL tree in-order.
    """
    def __init__(self):
        self.root = None

    def get_height(self, node):
        """Returns the height of the node."""
        if not node:
            return 0
        return node.height

    def get_balance(self, node):
        """Returns the balance factor of the node."""
        if not node:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)

    def right_rotate(self, y):
        """Performs a right rotation on the node."""
        x = y.left
        T2 = x.right
        x.right = y
        y.left = T2
        y.height = max(self.get_height(y.left), self.get_height(y.right)) + 1
        x.height = max(self.get_height(x.left), self.get_height(x.right)) + 1
        return x

    def left_rotate(self, x):
        """Performs a left rotation on the node."""
        y = x.right
        T2 = y.left
        y.left = x
        x.right = T2
        x.height = max(self.get_height(x.left), self.get_height(x.right)) + 1
        y.height = max(self.get_height(y.left), self.get_height(y.right)) + 1
        return y

    def insert(self, key):
        """Inserts a key into the AVL tree."""
        self.root = self._insert(self.root, key)

    def _insert(self, node, key):
        """Helper method to insert a key into the AVL tree."""
        if not node:
            return AVLNode(key)
        if key < node.key:
            node.left = self._insert(node.left, key)
        elif key > node.key:
            node.right = self._insert(node.right, key)
        else:
            return node
        node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
        balance = self.get_balance(node)
        if balance > 1 and key < node.left.key:
            return self.right_rotate(node)
        if balance < -1 and key > node.right.key:
            return self.left_rotate(node)
        if balance > 1 and key > node.left.key:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)
        if balance < -1 and key < node.right.key:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)
        return node

    def delete(self, key):
        """Deletes a key from the AVL tree."""
        self.root = self._delete(self.root, key)

    def _delete(self, node, key):
        """Helper method to delete a key from the AVL tree."""
        if not node:
            return node
        if key < node.key:
            node.left = self._delete(node.left, key)
        elif key > node.key:
            node.right = self._delete(node.right, key)
        else:
            if not node.left:
                return node.right
            if not node.right:
                return node.left
            temp = self.get_min_value_node(node.right)
            node.key = temp.key
            node.right = self._delete(node.right, temp.key)
        if not node:
            return node
        node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
        balance = self.get_balance(node)
        if balance > 1 and self.get_balance(node.left) >= 0:
            return self.right_rotate(node)
        if balance > 1 and self.get_balance(node.left) < 0:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)
        if balance < -1 and self.get_balance(node.right) <= 0:
            return self.left_rotate(node)
        if balance < -1 and self.get_balance(node.right) > 0:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)
        return node

    def get_min_value_node(self, node):
        """Returns the node with the minimum key value."""
        current = node
        while current.left:
            current = current.left
        return current

    def search(self, key):
        """Searches for a key in the AVL tree."""
        return self._search(self.root, key)

    def _search(self, node, key):
        """Helper method to search for a key in the AVL tree."""
        if not node or node.key == key:
            return node
        if key < node.key:
            return self._search(node.left, key)
        return self._search(node.right, key)

    def traverse(self):
        """Traverses and prints the AVL tree in-order."""
        def in_order(node):
            if node:
                in_order(node.left)
                print(node.key, end=" ")
                in_order(node.right)
        in_order(self.root)
        print()

# Example usage
if __name__ == "__main__":
    avl_tree = AVLTree()
    keys = [20, 15, 25, 10, 5, 30, 35]
    for key in keys:
        avl_tree.insert(key)
    print("AVL Tree (in-order):")
    avl_tree.traverse()
    avl_tree.delete(15)
    print("AVL Tree after deleting 15 (in-order):")
    avl_tree.traverse()
    found_node = avl_tree.search(25)
    if found_node:
        print(f"Node with key {found_node.key} found.")
    else:
        print("Node not found.")
