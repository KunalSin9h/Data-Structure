node= 4
edge = 6
inf = 99999999999999

# Using Adjacency of list to store graph data
graph = {{}}
#list to store the cost of every node
cost = []
for i in range(node):
    cost.append(inf)
#list to store the parent of every node
parent = []
for i in range(node):
    parent.append(None)
# All Vertex
graph["Start"] = {{"A", 6}, {"B", 2}}
graph["A"] = {{"Fin", 1}}
graph["B"] = {{"A", 3}, {"Fin", 5}}
graph["Fin"] = {}




