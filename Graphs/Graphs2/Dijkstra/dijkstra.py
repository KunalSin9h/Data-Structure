import heapq

INF = 2E9
N = 0

def dijkstra(source):
    dis = [INF]*N
    vis = [0]*N

    dis[source] = 0

