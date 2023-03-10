'''
Depth-First Search (DFS) is another algorithm used for searching through a graph or tree data structure. Like BFS, it is an uninformed search algorithm,
meaning it does not take into account any information about the goal or the cost of moving between nodes.

DFS starts at the root node (or any other arbitrary node) and explores as far as possible along each branch before backtracking. It explores each node 
in depth before moving on to the next node at the same level. This approach is similar to traversing a maze by following a single path until you reach a dead end, then backtracking to the previous intersection and choosing a different path.

DFS can be implemented using a stack data structure to keep track of the nodes to be visited. The stack starts with the starting node, and the algorithm
proceeds as follows:

Pop the next node from the stack.
If the popped node is the goal node, return the solution.
Otherwise, push all the neighboring nodes of the popped node that have not been visited onto the stack and mark them as visited.
Repeat steps 1-3 until the stack is empty or the goal node is found.
The time complexity of DFS is dependent on the branching factor (b) and the depth of the search space (d). In the worst-case scenario,
DFS may traverse the entire depth of the search space before finding the goal node, resulting in a time complexity of O(b^d). However, in some cases,
DFS can be more efficient than BFS, especially when the goal node is located closer to the starting node, or when the search space has a large branching
factor but a shallow depth.

One potential disadvantage of DFS is that it may get stuck in an infinite loop if there are cycles in the graph or tree. To avoid this,
a modification called iterative deepening DFS can be used, which limits the depth of the search and gradually increases it until the goal node is found.

The main advantages and disadvantages of Depth-First Search (DFS) are as follows:

Advantages:

Memory Efficiency: DFS uses less memory compared to Breadth-First Search (BFS)
since it only needs to store the path from the starting node to the current node.
Simplicity: DFS is a simple algorithm to implement and understand, especially for smaller search spaces.
Suitable for Graphs: DFS can be used to traverse graphs that may contain cycles, which cannot be handled by BFS.
Disadvantages:

Completeness: DFS is not complete in all cases since it may get stuck in an infinite loop if there are cycles in the graph or tree.
Non-Optimality: DFS may not find the shortest path to the goal node since it does not consider the cost of moving between nodes.
Time Complexity: The time complexity of DFS is dependent on the branching factor and the depth of the search space.
In the worst-case scenario, DFS may traverse the entire depth of the search space before finding the goal node, resulting in a time complexity of O(b^d),
where b is the branching factor and d is the depth of the search space.
Overall, DFS can be a useful algorithm for certain problems, especially those with large branching factors but shallow depths.
However, for more complex problems where optimality and completeness are important, other search algorithms like BFS or A* may be more suitable.
'''


def dfs(graph, start, goal):
    visited = set()    # to keep track of visited nodes
    stack = [start]    # initialize the stack with starting node
    
    while stack:
        node = stack.pop()    # get the next node from the stack
        if node == goal:      # if goal is found, return path
            return path
        if node not in visited:
            visited.add(node)    # mark node as visited
            stack.extend(graph[node] - visited)    # add unvisited neighbors to the stack
            
    return None    # if goal is not found, return None
