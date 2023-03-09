import heapq
from collections import defaultdict

class Graph:
    # Constructor
    def __init__(self) -> None:
        self.graph = defaultdict(list)

    def add_edge(self, u: int, v: int, cost: int) -> None:
        self.graph[u].append((v, cost))
        self.graph[v].append((u, cost))

    def A_star(self, start_node: int, target: int, heuristic: dict) -> None:
        '''
        Search the target node from the source node using A* algorithm
        Args:
             start_node: Source node from where the search will start: int
             target: Destination node: int
             heuristic: A dictionary containing the heuristic value for each node
        Returns:
            None
        '''
        print("Path: ", end="")
        queue = []
        heapq.heapify(queue)
        heapq.heappush(queue, (0 + heuristic[start_node], start_node))
        visited = set([start_node])
        while queue:
            node = heapq.heappop(queue)[1]
            print(node, end=" ")
            if node == target:
                break
            for child_node, cost in self.graph[node]:
                if child_node in visited:
                    continue
                visited.add(child_node)
                heapq.heappush(queue, (cost + heuristic[child_node], child_node))

if __name__ == '__main__':
    g = Graph()
    g.add_edge(0, 1, 3)
    g.add_edge(0, 2, 6)
    g.add_edge(0, 3, 5)
    g.add_edge(1, 4, 9)
    g.add_edge(1, 5, 8)
    g.add_edge(2, 6, 12)
    g.add_edge(2, 7, 14)
    g.add_edge(3, 8, 7)
    g.add_edge(8, 9, 5)
    g.add_edge(8, 10, 6)
    g.add_edge(9, 11, 1)
    g.add_edge(9, 12, 10)
    g.add_edge(9, 13, 2)

    # Heuristic function
    heuristic = {0: 14, 1: 12, 2: 11, 3: 6, 4: 8, 5: 6, 6: 4, 7: 3, 8: 4, 9: 0, 10: 2, 11: 1, 12: 4, 13: 4}

    source = 0
    target = 9
    print(f"Source Node: {source}") 
    print(f"Target Node: {target}")
    g.A_star(source, target, heuristic)
    print()
