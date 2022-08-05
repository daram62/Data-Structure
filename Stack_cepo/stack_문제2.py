class Stack():
    def __init__(self):
        self.stk = []
    
    def push(self,data):
        self.stk.append(data)
        
    def pop(self):
        pop_object = None
        if self.isEmpty():
            pop_object = -1
        else:
            pop_object = self.stk.pop()
        return pop_object

    def isEmpty(self):
        is_empty = 0
        if not self.stk:
            is_empty = 1
        return is_empty


stack = Stack()
cnt =int(input())
sum = 0
for i in range(0,cnt):
    num = int(input())
    if num == 0:
        stack.pop()
    else:
        stack.push(num)

while True:
    data = stack.pop()

    if data == -1 :
        break
    else:
        sum += data

print(sum)
    
    



