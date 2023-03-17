import sys

def tsp_bb(graph):
    """
    This function solves the Traveling Salesman Problem using Branch and Bound.
    Args:
        graph (list): A 2D list that represents the weighted graph.
    Returns:
        A tuple containing the minimum cost and the optimal tour.
    """
    n = len(graph)
    inf = sys.maxsize
    lower_bound = [0] * n
    upper_bound = [inf] * n
    tour = [0] * n
    stack = [(0, 0, lower_bound, tour)]
    min_cost = inf
    min_tour = []
    
    while stack:
        level, node, lb, curr_tour = stack.pop()
        if level == n:
            if graph[node][0] != inf:
                curr_cost = lb[node] + graph[node][0]
                if curr_cost < min_cost:
                    min_cost = curr_cost
                    min_tour = curr_tour
                    min_tour[-1] = 0
            continue
        
        for i in range(n):
            if graph[node][i] != inf and lb[node] + graph[node][i] < upper_bound[i]:
                new_lb = lb.copy()
                new_lb[node] += graph[node][i]
                new_tour = curr_tour.copy()
                new_tour[level] = i
                if level == n-1:
                    new_tour[-1] = 0
                stack.append((level+1, i, new_lb, new_tour))
                upper_bound[i] = new_lb[i]
    
    return min_cost, min_tour

# Example Usage
graph = [[0, 1, 15, 6],
         [2, 0, 7, 3],
         [9, 6, 0, 12],
         [10, 4, 8, 0]]
min_cost, min_tour = tsp_bb(graph)
print("Minimum Cost:", min_cost)
print("Optimal Tour:", min_tour)
