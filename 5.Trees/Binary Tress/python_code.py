class BTreeNode:
    """
    A node in a B-tree.

    Attributes:
        keys (list): A list of keys in the node.
        children (list): A list of children nodes.
        is_leaf (bool): A flag indicating if the node is a leaf.
    """
    def __init__(self, t, is_leaf=False):
        self.t = t  # Minimum degree
        self.is_leaf = is_leaf
        self.keys = []
        self.children = []

class BTree:
    """
    A B-tree class with basic B-tree operations.

    Attributes:
        root (BTreeNode): The root node of the B-tree.

    Methods:
        insert(key): Inserts a key into the B-tree.
        traverse(): Traverses and prints the B-tree.
    """
    def __init__(self, t):
        self.t = t
        self.root = BTreeNode(t, is_leaf=True)

    def traverse(self, node, level=0):
        """Traverses and prints the B-tree."""
        if node:
            print("Level", level, ":", node.keys)
            if not node.is_leaf:
                for child in node.children:
                    self.traverse(child, level + 1)

    def insert(self, key):
        """Inserts a key into the B-tree."""
        root = self.root
        if len(root.keys) == (2 * self.t - 1):
            s = BTreeNode(self.t, is_leaf=False)
            self.root = s
            s.children.append(root)
            self.split_child(s, 0)
            self.insert_non_full(s, key)
        else:
            self.insert_non_full(root, key)

    def insert_non_full(self, node, key):
        """Inserts a key into a node that is not full."""
        i = len(node.keys) - 1
        if node.is_leaf:
            node.keys.append(None)
            while i >= 0 and key < node.keys[i]:
                node.keys[i + 1] = node.keys[i]
                i -= 1
            node.keys[i + 1] = key
        else:
            while i >= 0 and key < node.keys[i]:
                i -= 1
            i += 1
            if len(node.children[i].keys) == (2 * self.t - 1):
                self.split_child(node, i)
                if key > node.keys[i]:
                    i += 1
            self.insert_non_full(node.children[i], key)

    def split_child(self, parent, i):
        """Splits the child of a node."""
        t = self.t
        y = parent.children[i]
        z = BTreeNode(t, is_leaf=y.is_leaf)
        parent.children.insert(i + 1, z)
        parent.keys.insert(i, y.keys[t - 1])
        z.keys = y.keys[t:(2 * t - 1)]
        y.keys = y.keys[0:(t - 1)]
        if not y.is_leaf:
            z.children = y.children[t:(2 * t)]
            y.children = y.children[0:t]

# Example usage
if __name__ == "__main__":
    btree = BTree(t=2)  # Create a B-tree with minimum degree 2
    keys = [10, 20, 5, 6, 15, 30, 25, 40, 50, 35]
    for key in keys:
        btree.insert(key)
    btree.traverse(btree.root)
