class Stack():
    def __init__(self):
        self.stack = []
        self.count = 0
    
    def push(self, data):
        self.stack.append(data)
        self.count +=1
    
    def isEmpty(self):
        is_empty= 0
        if not self.stack:
            is_empty = 1
        return is_empty

    def pop(self):
        pop_object= None
        if self.isEmpty():
            print("-1")
        else:
            pop_object =self.stack.pop()
            self.count -=1
            print(pop_object)
        return pop_object
    
    def top(self):
        top_object = None
        if self.isEmpty():
            print("-1")
        else:
            top_object = self.stack[-1]
            print(top_object)
        return top_object
stack = Stack()

cnt = int(input())
for i in range(0,cnt) :
    num = 0 
    order = input().split()

    
    if order[num] == 'push':
        stack.push(order[num+1])
        num += 1
    elif order[num] == 'top':
        stack.top()
    elif order[num] == 'size':
        print(stack.count)
    elif order[num] == 'empty':
        print(stack.isEmpty())
    elif order[num] == 'pop':
        stack.pop()
    num +=1
    


