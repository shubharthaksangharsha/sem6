import heapq

# Class representing a node in the puzzle
class PuzzleNode:
    def __init__(self, state, parent=None, action=None, cost=0):
        self.state = state
        self.parent = parent
        self.action = action
        self.cost = cost

    def __hash__(self):
        return hash(tuple(self.state))

    def __lt__(self, other):
        return self.cost < other.cost

    def __eq__(self, other):
        return self.state == other.state

# Function to calculate the total cost of reaching the current state
def calculate_cost(state, parent_cost):
    return parent_cost + 1

# Function to calculate the number of misplaced tiles
def misplaced_tiles(state):
    goal_state = [1, 2, 3, 4, 5, 6, 7, 8, 0]
    count = 0
    for i in range(9):
        if state[i] != goal_state[i]:
            count += 1
    return count

# Function to perform the A* search algorithm
def solve_puzzle(initial_state):
    open_list = []
    closed_list = set()

    # Create the initial node
    initial_node = PuzzleNode(initial_state)
    initial_node.cost = misplaced_tiles(initial_state)
    heapq.heappush(open_list, initial_node)

    while open_list:
        # Get the node with the minimum cost
        current_node = heapq.heappop(open_list)

        # Check if the current node is the goal state
        if current_node.state == [1, 2, 3, 4, 5, 6, 7, 8, 0]:
            path = []
            while current_node.parent is not None:
                path.append(current_node.action)
                current_node = current_node.parent
            path.reverse()
            return path

        # Generate the next possible moves
        empty_index = current_node.state.index(0)
        possible_moves = []
        if empty_index % 3 > 0:
            possible_moves.append(('left', empty_index - 1))
        if empty_index % 3 < 2:
            possible_moves.append(('right', empty_index + 1))
        if empty_index // 3 > 0:
            possible_moves.append(('up', empty_index - 3))
        if empty_index // 3 < 2:
            possible_moves.append(('down', empty_index + 3))

        # Generate child nodes and add them to the open list
        for move, index in possible_moves:
            new_state = list(current_node.state)
            new_state[empty_index], new_state[index] = new_state[index], new_state[empty_index]
            new_node = PuzzleNode(new_state, current_node, move, calculate_cost(new_state, current_node.cost))
            if new_node not in closed_list:
                new_node.cost += misplaced_tiles(new_state)
                heapq.heappush(open_list, new_node)
                closed_list.add(new_node)

    return None

# Example usage
initial_state = [1, 2, 3, 4, 5, 6, 0, 7, 8]
solution = solve_puzzle(initial_state)
if solution:
    print("Solution steps:")
    for step in solution:
        print(step)
else:
    print("No solution found.")
