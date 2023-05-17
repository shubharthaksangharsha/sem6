class MonkeyBananaProblem:
    def __init__(self, initial_state, target_location):
        self.initial_state = initial_state
        self.target_location = target_location

    def actions(self, state):
        """Returns a list of valid actions in a given state."""
        return ['left', 'right', 'up', 'down']

    def result(self, state, action):
        """Returns the state that results from taking a certain action in a given state."""
        x, y = state
        if action == 'left':
            return x - 1, y
        elif action == 'right':
            return x + 1, y
        elif action == 'up':
            return x, y + 1
        elif action == 'down':
            return x, y - 1
        else:
            return state

    def is_goal_state(self, state):
        """Checks if the given state is the goal state."""
        return state == self.target_location

    def heuristic(self, state):
        """Estimates the cost of reaching the goal state from a given state (heuristic function)."""
        x, y = state
        target_x, target_y = self.target_location
        return abs(x - target_x) + abs(y - target_y)

    def solve(self):
        """Solves the monkey banana problem using A* search algorithm."""
        start_state = self.initial_state
        if self.is_goal_state(start_state):
            return []

        frontier = [(start_state, [])]  # (state, path)
        explored = set()

        while frontier:
            state, path = frontier.pop(0)
            explored.add(state)

            for action in self.actions(state):
                next_state = self.result(state, action)
                if next_state not in explored:
                    new_path = path + [action]
                    if self.is_goal_state(next_state):
                        return new_path
                    frontier.append((next_state, new_path))
                    frontier.sort(key=lambda x: len(x[1]) + self.heuristic(x[0]))

        return None


# Example usage:
initial_state = (0, 0)
target_location = (4, 2)
problem = MonkeyBananaProblem(initial_state, target_location)
solution = problem.solve()
print(solution)
