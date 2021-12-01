class Stack:
    def __init__(self):
        self.size = 0
        self.underlist = [] # Under lying list

    def empty(self):
        return self.size == 0
    
    def size(self):
        return self.size

    def push(self, key):
        self.underlist.append(key)
        self.size += 1

    def top(self):
        return self.underlist[(self.size - 1)]

    def pop(self):
        del self.underlist[(self.size - 1)] 
        self.size -= 1
    
   

books = Stack()
books.push(10)
books.push(1000)
books.info()
n = books.top()
print(n)
