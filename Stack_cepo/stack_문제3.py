class Stack():
    def __init__(self):
        self.stk = []
        self.size = 0
    
    def push(self,data):
        self.stk.append(data)
        self.size += 1

    def pop(self):
        pop_object = None
        self.size -= 1
        if self.isEmpty():
            pop_object = -1
        else :
            pop_object = self.stk.pop()
        return pop_object
    
    def isEmpty(self):
        is_empty = 0
        if not self.stk:
            is_empty = 1
        return is_empty

stack=Stack()
cnt = int(input())
for i in range(0,cnt):
    cmd= input()
    for i in range(0,len(cmd)):
        num = 0;
        if cmd[i] == '(':
            stack.push(i)
        else:
            stack.pop()
    if stack.size == 0:
        print("YES")
    else: 
        print("NO")
    cmd.clear()
    
