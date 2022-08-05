class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    
class LinkedList:
    def __init__(self, data):
        self.head = Node(data)

    def append(self, data):
        cur = self.head
        while cur.next is not None:
            cur = cur.next
        cur.next = Node(data)

    def insertfirst(self,data):
        new_node = Node(data)
        temp_node = self.head
        self.head = new_node
        self.head.next = temp_node

    def print_all(self):
        cur = self.head
        while cur is not None:
            print(cur.data)
            cur = cur.next
    
    def get_node(self, index):
        cnt = 0
        while cnt < index:
            node =  node.next
            cnt +=1
        return node

    def add_node(self, index, value):
        new_node == Node(value)
        if index == 0:
            new_node.next = self.head
            self.head = new_node
            return
        node = self.get_node(index-1)
        next_node = node.next
        node.next = new_node
        new_node.next = next_node

    def delete_node(self, index):
        if index == 0:
            self.head = self.head.next
            return
        node = self.get.node(index-1)
        node.next = node.next.next


if __name__ == "__main__":
    m_list = LinkedList(1)
    m_list.append(5)
    m_list.append(6)
    print('LinkedList :', m_list)
   