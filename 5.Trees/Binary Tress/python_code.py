class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert_level_order(self.root, key)

    def _insert_level_order(self, root, key):
        queue = [root]
        while queue:
            temp = queue.pop(0)
            if temp.left is None:
                temp.left = Node(key)
                return
            else:
                queue.append(temp.left)
            if temp.right is None:
                temp.right = Node(key)
                return
            else:
                queue.append(temp.right)

    def search(self, key):
        return self._search_level_order(self.root, key)

    def _search_level_order(self, root, key):
        if root is None:
            return None
        queue = [root]
        while queue:
            temp = queue.pop(0)
            if temp.key == key:
                return temp
            if temp.left:
                queue.append(temp.left)
            if temp.right:
                queue.append(temp.right)
        return None

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
bt = BinaryTree()
bt.insert(1)
bt.insert(2)
bt.insert(3)
bt.insert(4)
bt.insert(5)
bt.insert(6)
bt.insert(7)

print("Inorder traversal:")
bt.inorder_traversal()  # Output: 4 2 5 1 6 3 7

print("Preorder traversal:")
bt.preorder_traversal()  # Output: 1 2 4 5 3 6 7

print("Postorder traversal:")
bt.postorder_traversal()  # Output: 4 5 2 6 7 3 1

print("Search for 4:", "Found" if bt.search(4) else "Not Found")
print("Search for 10:", "Found" if bt.search(10) else "Not Found")
