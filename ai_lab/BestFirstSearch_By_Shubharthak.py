# By Shubharthak
from collections import defaultdict, deque
import heapq


class Graph:
    # Constructor
    def __init__(self) -> None:
        self.graph = defaultdict(list)

    def addedge(self, u: int, v: int, cost: int) -> None:
        self.graph[u].append((v, cost))
        self.graph[v].append((u, cost))

    def BFS(self, start_node: int, target: int) -> None:
        '''
        Search the target node from the source node
        Args:
             start_node: Source node from where the search will start: int
             target: Destination node: int
        Returns:
            None
        '''
        print("Path: ", end="")
        queue = []
        heapq.heapify(queue)
        heapq.heappush(queue, (0, start_node))
        visited = set([start_node])
        while queue:
            node = heapq.heappop(queue)[1]
            print(node, end=" ")
            if node == target:
                break
            for child_node, cost in self.graph[node]:
                if child_node in visited: continue
                visited.add(child_node)
                heapq.heappush(queue, (cost, child_node))


if __name__ == '__main__':
    g = Graph()
    g.addedge(0, 1, 3)
    g.addedge(0, 2, 6)
    g.addedge(0, 3, 5)
    g.addedge(1, 4, 9)
    g.addedge(1, 5, 8)
    g.addedge(2, 6, 12)
    g.addedge(2, 7, 14)
    g.addedge(3, 8, 7)
    g.addedge(8, 9, 5)
    g.addedge(8, 10, 6)
    g.addedge(9, 11, 1)
    g.addedge(9, 12, 10)
    g.addedge(9, 13, 2)
    source = 0
    target = 9
    print(f"Source Node: {source}") 
    print(f"Target Node: {target}")
    g.BFS(source, target)
    print()
