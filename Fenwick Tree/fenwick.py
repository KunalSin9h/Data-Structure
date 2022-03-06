# First Operation is to find T(i) = A[g(i), i]
#G function To find sum
g = lambda i: i&(i+1)
#H function to Update
h = lambda i: i|(i+1)

def S(i, j, A):
    res = 0
    for x in range(i, j+1):
        res += A[x]
    return res

class Fenwick:

    # convert an existing array into Fenwick Twee
    def __init__(self, A):
        self.n = len(A)
        self.T = [0]*self.n
        for i in range(self.n):
            self.add(i, A[i])

    # Sum find the sum of Element in A[0, r]  
    # O(log n)
    def sum(self, r):
        res = 0
        while r >= 0:
            res += self.T[r]
            r = g(r) - 1
        return res

    # A[i] += x
    # O(log n) -> Modified
    def add(self, i, x):
        while i < self.n:
            self.T[i] += x
            i = h(i)


A = [1, 2, 3, 4, 5]
Tree = Fenwick(A)
print(*Tree.T)

print(Tree.sum(3))
Tree.add(2, 1)

print(*Tree.T)