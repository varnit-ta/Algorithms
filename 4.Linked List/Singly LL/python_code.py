class Node:
    """
    A Node in a singly linked list.

    Attributes:
        data (any): The data stored in the node.
        next (Node): The reference to the next node in the list.
    """
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    """
    A Singly Linked List class with basic list operations.

    Attributes:
        head (Node): The head node of the list.

    Methods:
        append(data): Adds a node with the given data to the end of the list.
        prepend(data): Adds a node with the given data to the beginning of the list.
        delete(data): Deletes the first node containing the given data.
        search(data): Searches for a node containing the given data.
        display(): Displays the list as a sequence of data elements.
    """
    def __init__(self):
        """Initializes an empty singly linked list."""
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

    def prepend(self, data):
        """Adds a node with the given data to the beginning of the list."""
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def delete(self, data):
        """Deletes the first node containing the given data."""
        if not self.head:
            return
        if self.head.data == data:
            self.head = self.head.next
            return
        current_node = self.head
        while current_node.next and current_node.next.data != data:
            current_node = current_node.next
        if current_node.next:
            current_node.next = current_node.next.next

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
        elements = []
        while current_node:
            elements.append(current_node.data)
            current_node = current_node.next
        print(" -> ".join(map(str, elements)))

# Example usage
if __name__ == "__main__":
    sll = SinglyLinkedList()
    sll.append(1)
    sll.append(2)
    sll.append(3)
    sll.display()
    sll.prepend(0)
    sll.display()
    sll.delete(2)
    sll.display()
    node = sll.search(3)
    if node:
        print(f"Node with data {node.data} found.")
    else:
        print("Node not found.")
