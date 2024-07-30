class Node:
    """
    A Node in a doubly linked list.

    Attributes:
        data (any): The data stored in the node.
        next (Node): The reference to the next node in the list.
        prev (Node): The reference to the previous node in the list.
    """
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    """
    A Doubly Linked List class with basic list operations.

    Attributes:
        head (Node): The head node of the list.

    Methods:
        append(data): Adds a node with the given data to the end of the list.
        prepend(data): Adds a node with the given data to the beginning of the list.
        delete(data): Deletes the first node containing the given data.
        search(data): Searches for a node containing the given data.
        display(): Displays the list as a sequence of data elements.
        display_reverse(): Displays the list from the end to the beginning.
    """
    def __init__(self):
        """Initializes an empty doubly linked list."""
        self.head = None

    def append(self, data):
        """Adds a node with the given data to the end of the list."""
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node
        new_node.prev = last_node

    def prepend(self, data):
        """Adds a node with the given data to the beginning of the list."""
        new_node = Node(data)
        if self.head:
            self.head.prev = new_node
        new_node.next = self.head
        self.head = new_node

    def delete(self, data):
        """Deletes the first node containing the given data."""
        current_node = self.head
        while current_node:
            if current_node.data == data:
                if current_node.prev:
                    current_node.prev.next = current_node.next
                if current_node.next:
                    current_node.next.prev = current_node.prev
                if current_node == self.head:
                    self.head = current_node.next
                return
            current_node = current_node.next

    def search(self, data):
        """Searches for a node containing the given data."""
        current_node = self.head
        while current_node:
            if current_node.data == data:
                return current_node
            current_node = current_node.next
        return None

    def display(self):
        """Displays the list as a sequence of data elements."""
        current_node = self.head
        while current_node:
            print(current_node.data, end=" <-> ")
            current_node = current_node.next
        print("None")

    def display_reverse(self):
        """Displays the list from the end to the beginning."""
        current_node = self.head
        last_node = None
        while current_node:
            last_node = current_node
            current_node = current_node.next
        while last_node:
            print(last_node.data, end=" <-> ")
            last_node = last_node.prev
        print("None")

# Example usage
if __name__ == "__main__":
    dll = DoublyLinkedList()
    dll.append(1)
    dll.append(2)
    dll.append(3)
    dll.display()
    dll.prepend(0)
    dll.display()
    dll.delete(2)
    dll.display()
    dll.display_reverse()
    node = dll.search(3)
    if node:
        print(f"Node with data {node.data} found.")
    else:
        print("Node not found.")
