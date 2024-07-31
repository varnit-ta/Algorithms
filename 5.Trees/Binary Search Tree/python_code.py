class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert_recursive(self.root, key)

    def _insert_recursive(self, root, key):
        if root is None:
            return Node(key)
        if key < root.key:
            root.left = self._insert_recursive(root.left, key)
        else:
            root.right = self._insert_recursive(root.right, key)
        return root

    def remove(self, key):
        self.root = self._remove_recursive(self.root, key)

    def _remove_recursive(self, root, key):
        if root is None:
            return root

        if key < root.key:
            root.left = self._remove_recursive(root.left, key)
        elif key > root.key:
            root.right = self._remove_recursive(root.right, key)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left

            min_larger_node = self._get_min(root.right)
            root.key = min_larger_node.key
            root.right = self._remove_recursive(root.right, min_larger_node.key)

        return root

    def _get_min(self, root):
        while root.left is not None:
            root = root.left
        return root

    def search(self, key):
        return self._search_recursive(self.root, key)

    def _search_recursive(self, root, key):
        if root is None or root.key == key:
            return root
        if key < root.key:
            return self._search_recursive(root.left, key)
        return self._search_recursive(root.right, key)

    def inorder_traversal(self):
        self._inorder_recursive(self.root)
        print()

    def _inorder_recursive(self, root):
        if root:
            self._inorder_recursive(root.left)
            print(root.key, end=" ")
            self._inorder_recursive(root.right)

    def preorder_traversal(self):
        self._preorder_recursive(self.root)
        print()

    def _preorder_recursive(self, root):
        if root:
            print(root.key, end=" ")
            self._preorder_recursive(root.left)
            self._preorder_recursive(root.right)

    def postorder_traversal(self):
        self._postorder_recursive(self.root)
        print()

    def _postorder_recursive(self, root):
        if root:
            self._postorder_recursive(root.left)
            self._postorder_recursive(root.right)
            print(root.key, end=" ")

# Example usage
bst = BinarySearchTree()
bst.insert(50)
bst.insert(30)
bst.insert(70)
bst.insert(20)
bst.insert(40)
bst.insert(60)
bst.insert(80)

print("Inorder traversal:")
bst.inorder_traversal()  # Output: 20 30 40 50 60 70 80

print("Preorder traversal:")
bst.preorder_traversal()  # Output: 50 30 20 40 70 60 80

print("Postorder traversal:")
bst.postorder_traversal()  # Output: 20 40 30 60 80 70 50

print("Search for 40:", "Found" if bst.search(40) else "Not Found")
print("Search for 90:", "Found" if bst.search(90) else "Not Found")

bst.remove(70)
print("Inorder traversal after removing 70:")
bst.inorder_traversal()  # Output: 20 30 40 50 60 80
