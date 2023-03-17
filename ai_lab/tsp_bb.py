'''
The code solves the Traveling Salesman Problem (TSP) using the Branch and Bound algorithm. The TSP is a well-known optimization problem in which we are given a list of cities and the distances between them, and we need to find the shortest possible route that visits every city exactly once and returns to the starting city. The Branch and Bound algorithm is a common technique for solving optimization problems, in which we systematically explore the solution space by branching on different possibilities and pruning branches that are unlikely to lead to a better solution.

Let's go through the code step by step:

Import the sys module, which provides access to some variables used or maintained by the Python interpreter.

Define the calculate_lower_bound function, which takes in a graph and a path and calculates a lower bound on the total cost of the path. The lower bound is simply the sum of the weights of the edges in the path. This is a heuristic that allows us to discard branches that are guaranteed to be suboptimal.

Define the branch_and_bound function, which takes in a graph and returns the optimal path and its cost. The function initializes some variables, including a queue to store the nodes that we need to explore, and the best_path and best_path_cost variables to store the optimal path and its cost. The initial node in the queue is the starting node (node 0) with a cost of 0 and an empty path.

The function enters a while loop that continues until the queue is empty. In each iteration, the function pops the first node from the queue and unpacks its cost and path.

If the path is complete (i.e., it includes all the nodes in the graph), the function calculates the cost of the path by adding the weight of the edge that connects the last node in the path to the starting node. If the cost of the path is lower than the current best_path_cost, the function updates the best_path and best_path_cost variables.

Otherwise, the function generates child nodes by adding one node at a time to the path, provided that the node is not already in the path. For each child node, the function calculates its cost by adding the weight of the edge that connects it to the last node in the path. The function also calculates a lower bound on the cost of the remaining nodes by calling the calculate_lower_bound function. If the sum of the child node cost and the lower bound is lower than the current best_path_cost, the child node is added to the queue.

Once the queue is empty, the function returns the best_path and best_path_cost.

The rest of the code defines a graph, prints it, and calls the branch_and_bound function to solve the problem. The results are then printed.


'''
import sys
# Define a function to calculate the lower bound of a given path
def calculate_lower_bound(graph, path):
    lower_bound = 0
    for i in range(len(path) - 1):
        lower_bound += graph[path[i]][path[i+1]]
    return lower_bound

# Define the Branch and Bound algorithm
def branch_and_bound(graph):
    # Initialize variables
    n = len(graph)
    best_path = None
    best_path_cost = sys.maxsize
    queue = [(0, [0])]
    
    # Loop until the queue is empty
    while queue:
        # Get the next node from the queue
        node_cost, path = queue.pop(0)
        last_node = path[-1]
        
        # If the path is complete, update the best path
        if len(path) == n:
            path_cost = node_cost + graph[last_node][0]
            if path_cost < best_path_cost:
                best_path = path
                best_path_cost = path_cost
        
        # Otherwise, generate child nodes and add them to the queue
        else:
            for i in range(n):
                if i not in path:
                    child_cost = node_cost + graph[last_node][i]
                    child_lower_bound = calculate_lower_bound(graph, path + [i])
                    if child_cost + child_lower_bound < best_path_cost:
                        queue.append((child_cost, path + [i]))
    
    # Return the best path and its cost
    return best_path, best_path_cost

# Example usage
if __name__ == '__main__':
    # Define the graph
    graph = [
        [0, 1, 15, 6],
        [2, 0, 7, 3],
        [9, 6, 0, 12],
        [10, 4, 8, 0]
    ]
    
    # Print the graph
    print('   ', end='')
    for i in range(len(graph)):
        print(chr(65+i), end='     ')
    print()

    for i in range(len(graph)):
        print(chr(65+i), end='  ')
        for j in range(len(graph[i])):
            print('{:<5}'.format(graph[i][j]), end=' ')
        print()

    # Solve the problem using Branch and Bound
    best_path, best_path_cost = branch_and_bound(graph)
    
    # Print the results
    print('\nMinimum Cost:', best_path_cost)
    print('Optimal Tour:', end=' ')
    for i in range(len(best_path)):
        print(chr(65+best_path[i]), end=' ')
    print(chr(65), end='')
