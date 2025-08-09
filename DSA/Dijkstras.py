import heapq
import sys 

def construct_adj(edges, v):
    adj = [[] for _ in range(v)]

    for ele in edges:
        u, v, w = ele[0], ele[1], ele[2]
        adj[u].append([v, w])
        adj[v].append([u, w])
    return adj

def Dijkstra(edges, v, src):

    # construct the adj list 
    adj = construct_adj(edges, v)
    # distance list 
    dist = [sys.maxsize]*v
    # priority queue 
    pq = []
    heapq.heappush(pq, [0, src])
    dist[src] = 0

    while pq:
        u = heapq.heappop(pq)[1]
        
        for x in adj[u]:
            vertex, weight = x[0], x[1]
            if (dist[vertex] > dist[u] + weight ):
                dist[vertex] = dist[u] + weight
                heapq.heappush(pq, [dist[vertex], vertex])
    return dist 

    pass 













# list of edges 
# [u, v , weight]
edges = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]]
# v - num of vertices 
v = 5
src = 0
print(Dijkstra(edges, v, src))