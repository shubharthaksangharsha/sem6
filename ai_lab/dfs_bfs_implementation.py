#By Shubharthak
from collections import defaultdict, deque

class Graph:
    #Constructor 
    def __init__(self) -> None:
        self.graph = defaultdict(list)
    
    def addEdge(self, u: int, v: int) -> None:
        self.graph[u].append(v)

    def bfs(self, start_node: int) -> None:
        '''
        Prints the Node in Level Order of the given start_node.
        input: start_node: int
        output: None
        '''
        d = deque([start_node])
        list_of_nodes = []
        visited = set([start_node])
        while d:
            node = d.popleft()
            print(node, end=" ")
            list_of_nodes.append(node)
            for child_node in self.graph[node]:
                if child_node in visited: continue
                visited.add(child_node)
                d.append(child_node)
    
    def dfs_preoder(self, start_node: int) -> None:
        '''
        Prints the Node in Prerder of the given start_node
        input: start_node: int
        output: None
        '''
        visited = set([start_node])
        def recurse(start_node):
            print(start_node, end=" ")
            for child_node in self.graph[start_node]:
                if child_node in visited: continue
                visited.add(child_node)
                recurse(child_node)
        recurse(start_node)

if __name__ == '__main__':
    g = Graph()
    g.addEdge(1, 2)
    g.addEdge(1, 3)
    g.addEdge(2, 1)
    g.addEdge(2, 6)
    g.addEdge(3, 1)
    g.addEdge(3, 4)
    g.addEdge(3, 5)
    g.addEdge(4, 3)
    g.addEdge(4, 5)
    g.addEdge(5, 3)
    g.addEdge(5, 4)
    g.addEdge(6, 2)
    g.bfs(1)
    print()
    g.dfs_preoder(1)
    print()
    