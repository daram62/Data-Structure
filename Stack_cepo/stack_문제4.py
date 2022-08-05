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
    
    def top(self):
        top_object = 0
        if self.isEmpty():
           top_object = 0  
        else:
            top_object = self.stk[-1]
        
        return top_object
    
stack = Stack()
cnt = int(input())
numlist = []
stack.push(1)
order = []
final = []
order.append('+')
for i in range(0,cnt):
    data = input()
    numlist.append(data)

num = 2

for j in range(0,len(numlist)):
    data = int(numlist[j]) 
   
    while True:
        
        if stack.top() < data :
            stack.push(num)
            order.append('+')
            
            num +=1
            
        if stack.top() == data:
            stack.pop()
            order.append('-')
            break
            
        if stack.isEmpty == 0:
            print("종료")
            break
        if stack.top() > data:
            final ="NO"
            break
    if final == 'NO':
        print(final)
        break
if final != 'NO':
    for i in range (0,len(order)):
        print(order[i])
