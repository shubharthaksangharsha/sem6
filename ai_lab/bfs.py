import heapq

# Define the heuristic function to estimate the cost of reaching the goal
def heuristic(node, goal):
    # Here, we use the Euclidean distance as the heuristic function
    return ((node[0] - goal[0]) ** 2 + (node[1] - goal[1]) ** 2) ** 0.5

# Define the Best-First Search function
def best_first_search(graph, start, goal):
    # Create a priority queue to store the nodes to be expanded
    queue = [(heuristic(start, goal), start)]
    visited = set()
    # Iterate until the queue is empty
    while queue:
        # Get the node with the lowest heuristic value from the queue
        (cost, current_node) = heapq.heappop(queue)
        # Check if we have reached the goal
        if current_node == goal:
            return True
        # Add the current node to the visited set
        visited.add(current_node)
        # Expand the neighbors of the current node
        for neighbor in graph[current_node]:
            # Check if the neighbor has already been visited
            if neighbor not in visited:
                # Calculate the heuristic value for the neighbor
                neighbor_cost = heuristic(neighbor, goal)
                # Add the neighbor to the queue with its heuristic value as priority
                heapq.heappush(queue, (neighbor_cost, neighbor))
    # If the goal is not reachable from the start node, return False
    return False

# Example usage
graph = {
    (0, 0): [(0, 1), (1, 0)],
    (0, 1): [(0, 0), (1, 1)],
    (1, 0): [(0, 0), (1, 1)],
    (1, 1): [(0, 1), (1, 0), (2, 2)],
    (2, 2): []
}

start = (0, 0)
goal = (2, 2)

if best_first_search(graph, start, goal):
    print("Goal reached!")
else:
    print("Goal not reachable!")
