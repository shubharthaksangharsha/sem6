from collections import defaultdict, deque
import heapq
import math
'''
euclidean_distance:
This function calculates the Euclidean distance between two nodes in a two-dimensional grid. In the context of pathfinding algorithms like A* search, Euclidean distance is often used as a heuristic to estimate the distance between a node and the goal node. The heuristic function is used to guide the search algorithm towards the goal node by considering both the actual cost from the start node to the current node and an estimate of the remaining cost to reach the goal node.

The Euclidean distance is the straight-line distance between two points in a two-dimensional space, calculated as the square root of the sum of the squared differences of their x and y coordinates. In the context of A* search, the Euclidean distance is used as an estimate of the remaining distance to the goal node. This can be a good estimate when the search space is relatively open and unobstructed, but may not be as accurate in more complex or maze-like environments.

Here's an example of how euclidean_distance function works:

Suppose we have a two-dimensional grid and two nodes A and B at coordinates (1, 2) and (4, 5) respectively. The Euclidean distance between A and B can be calculated as follows:

distance = sqrt((4 - 1)^2 + (5 - 2)^2)
= sqrt(3^2 + 3^2)
= sqrt(18)
= 4.24




node_to_coordinates:
This function takes a node number as input and converts it to its corresponding x and y coordinates on a two-dimensional grid. In the context of pathfinding algorithms, nodes are often represented as integers, and it can be helpful to convert them to their corresponding coordinates to visualize the search space or calculate distances between nodes.

The function assumes a specific layout of the nodes on the grid, where the nodes are numbered from left to right and top to bottom, starting at 0. For example, in a 3x5 grid, the node numbering would look like this:


0  1  2  3  4
5  6  7  8  9
10 11 12 13 14


Given a node number, the function calculates its x and y coordinates as follows:

x = node_number % grid_width
y = node_number // grid_width

For example, if we pass in node number 7 for a 3x5 grid, the function would return coordinates (2, 1), which corresponds to the third column and second row of the grid.
'''
class Graph:
    # Constructor
    def __init__(self) -> None:
        self.graph = defaultdict(list)

    def addedge(self, u: int, v: int, cost: int) -> None:
        self.graph[u].append((v, cost))
        self.graph[v].append((u, cost))

    def astar(self, start_node: int, target: int) -> None:
        '''
        Search the target node from the source node using A* search algorithm
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
                cost_to_child = cost + self.euclidean_distance(child_node, target)
                heapq.heappush(queue, (cost_to_child, child_node))

    def euclidean_distance(self, node1: int, node2: int) -> float:
        '''
        Calculates the Euclidean distance between two nodes
        Args:
            node1: First node: int
            node2: Second node: int
        Returns:
            Euclidean distance between the two nodes: float
        '''
        x1, y1 = self.node_to_coordinates(node1)
        x2, y2 = self.node_to_coordinates(node2)
        return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

    def node_to_coordinates(self, node: int) -> tuple:
        '''
        Converts a node number to its x and y coordinates on a 2D grid
        Args:
            node: Node number: int
        Returns:
            Tuple containing the x and y coordinates of the node: tuple
        '''
        # Example implementation for a 3x5 grid:
        x = node % 5
        y = node // 5
        return x, y


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
    g.astar(source, target)
    print()
