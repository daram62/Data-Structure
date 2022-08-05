class Stack():
    def __init__(self):
        self.stack = []
    
    def push(self, data):
        self.stack.append(data)
    
    def isEmpty(self):
        is_empty= False
        if not self.stack:
            is_empty = True
        return is_empty

    def pop(self):
        pop_object= None
        if self.isEmpty():
            print("Stack is empty")
        else:
            pop_object =self.stack.pop()

        return pop_object
    
    def top(self):
        top_object = None
        if self.isEmpty():
            print("Stack is empty")
        else:
            top_object = self.stack[-1]
        
        return top_object
stack = Stack()

cnt = int(input())
for i in range(1,cnt) :4

    order = input()
    print(order)






print(stack.stack)
