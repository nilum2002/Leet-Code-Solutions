import heapq
import networkx as nx 
import matplotlib.pyplot as plt 

class Node:
    def __init__(self, name, heuristic):
        self.name = name 
        self.heuristic = heuristic
    # compare nodes based on their heuristic values 
    def __lt__(self,other ):
        return self.heuristic < other.heuristic
        
# reconstruct the path 
def reconstruct_path(path, start, goal):
    print(path)
    curr = goal 
    res_path = []
    while curr is not None:
        res_path.append(curr)
        curr = path[curr]
    res_path.reverse()
    return res_path

# greedy best first search algorithm 
def greedy_best_first_search_hierarchical(graph, start, goal, heuristic, region_map ):
   
    pq = []
    heapq.heappush(pq, Node(start, heuristic[start]))


    visited = set()

    path = {start: None}

    while pq:
        
        curr_node = heapq.heappop(pq).name 
        if curr_node == goal:
            return reconstruct_path(path, start, goal)
        visited.add(curr_node)

        curr_region = region_map[curr_node]

        for neighbor in graph[curr_node]:
            if neighbor not in visited and region_map[neighbor] == curr_region:
                heapq.heappush(pq, Node(neighbor, heuristic[neighbor]))
                if neighbor not in path:
                    path[neighbor] = curr_node
        for neighbor in graph[curr_node]:
            if neighbor not in visited and region_map[neighbor] != curr_region:
                heapq.heappush(pq, Node(neighbor, heuristic[neighbor]))
                if neighbor not in path:
                    path[neighbor] = curr_node
    return None
    pass



graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': ['H'],
    'E': ['I', 'J'],
    'F': ['K' , 'M' , 'E'],
    'G': ['L', 'M'],
    'H': [],
    'I': [],
    'J': [],
    'K': [],
    'L': [],
    'M': []
}

heuristic = {
    'A': 8,
    'B': 6,
    'C': 7,
    'D': 5,
    'E': 4,
    'F': 5,
    'G': 4,
    'H': 3,
    'I': 2,
    'J': 1,
    'K': 3,
    'L': 2,
    'M': 1
}

region_map = {
    'A': 1, 'B': 1, 'C': 1,
    'D': 2, 'E': 2,
    'F': 3, 'G': 3,
    'H': 2, 'I': 2, 'J': 2,
    'K': 3, 'L': 3, 'M': 3
}
start = "A"
goal = "M"


res = greedy_best_first_search_hierarchical(graph,start, goal, heuristic, region_map)
print(res)