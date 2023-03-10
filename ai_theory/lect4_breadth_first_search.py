'''
Breadth-first search (BFS) is an uninformed search algorithm used to explore all the nodes in a graph or tree.
It starts at the root node (or any arbitrary node in the graph) and explores all the neighboring nodes at
the current depth before moving on to nodes at the next depth. It continues this process until it reaches the goal node or all nodes have been explored.

The algorithm can be summarized as follows:

Create a queue and add the start node to it.
Mark the start node as visited.
While the queue is not empty, do the following:
a. Remove the first node from the queue.
b. If the node is the goal node, return the solution.
c. Otherwise, add all the unvisited neighbors of the node to the queue and mark them as visited.
If the queue becomes empty and the goal node has not been found, then there is no solution.
BFS explores all the neighboring nodes of the current node before moving on to nodes at the next depth. 
This ensures that the shortest path to each node is found before longer paths are considered.

The time complexity of BFS is O(|V| + |E|), where |V| is the number of vertices (nodes) in the graph and |E| is the number of edges.
This is because BFS must visit each vertex and each edge in the graph once.
Advantages of Breadth-First Search (BFS) Algorithm:

BFS guarantees to find the shortest path from the starting node to the goal node if the graph is unweighted or all edge costs are equal.
It explores all nodes at the same level before moving on to nodes at the next level. This property makes it suitable for finding the shortest path.
BFS is complete, meaning it will always find a solution if one exists.
It can also be used to find all nodes within a certain distance from the starting node.
Disadvantages of Breadth-First Search (BFS) Algorithm:

BFS can be very memory-intensive, especially for large graphs or trees. This is because it needs to store all the
nodes at a given depth before moving on to nodes at the next depth.
The time complexity of BFS is O(|V| + |E|), where |V| is the number of vertices and |E| is the number of edges.
This can be slow for large graphs or trees.
BFS may not be efficient for problems where the cost of moving between nodes varies.
This is because it does not consider the cost of reaching a node, only its distance from the starting node.
BFS may also be inefficient for graphs or trees with very deep levels, as it needs to explore all nodes at each level 
before moving on to nodes at the next level.

The time complexity of Breadth-First Search (BFS) algorithm in terms of the branching factor (b) and the depth of the shallowest solution (d) is given by O(b^d).

This means that the time complexity of BFS grows exponentially with the depth of the shallowest solution and 
the branching factor of the search space. The branching factor represents the number of children each node has, while the depth of the shallowest solution is the depth of the solution closest to the root node.

The space complexity of BFS is also dependent on the branching factor and depth of the shallowest solution.
In the worst-case scenario, all nodes at the deepest level must be stored in the memory, which can result in high space requirements.

Therefore, for large branching factors and deep search spaces, the time and space complexity of BFS can become 
very high, making it impractical for certain problems. In such cases, other search algorithms like Depth-First Search (DFS) or A* may be more suitable
'''
def bfs(graph, start, goal):
    """
    Finds the shortest path from start to goal in the graph using BFS.
    """
    # Initialize the queue and visited set
    queue = [start]
    visited = {start}

    # Initialize the parent dictionary
    parent = {start: None}

    # Loop until the queue is empty
    while queue:
        # Remove the first node from the queue
        current = queue.pop(0)

        # If we've reached the goal, return the path
        if current == goal:
            path = []
            while current is not None:
                path.append(current)
                current = parent[current]
            return list(reversed(path))

        # Expand the current node's neighbors
        for neighbor in graph[current]:
            # If the neighbor has not been visited, add it to the queue
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
                parent[neighbor] = current

    # If we've searched the entire graph and haven't found the goal, return None
    return None

 graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

start = 'A'
goal = 'F'
path = bfs(graph, start, goal)
print(path)  # Output: ['A', 'C', 'F']
