class WaterJugProblem:
    def __init__(self, jug1_capacity, jug2_capacity, target_amount):
        self.jug1_capacity = jug1_capacity
        self.jug2_capacity = jug2_capacity
        self.target_amount = target_amount
        self.visited_states = set()
        self.solution_found = False

    def solve(self):
        self._dfs(0, 0)

    def _dfs(self, jug1_amount, jug2_amount):
        if self.solution_found:
            return

        if (jug1_amount, jug2_amount) in self.visited_states:
            return

        self.visited_states.add((jug1_amount, jug2_amount))

        if jug1_amount == self.target_amount or jug2_amount == self.target_amount:
            print("Solution found!")
            self.solution_found = True
            return

        # Empty jug1
        self._dfs(0, jug2_amount)

        # Empty jug2
        self._dfs(jug1_amount, 0)

        # Fill jug1
        self._dfs(self.jug1_capacity, jug2_amount)

        # Fill jug2
        self._dfs(jug1_amount, self.jug2_capacity)

        # Pour from jug1 to jug2
        amount_to_pour = min(jug1_amount, self.jug2_capacity - jug2_amount)
        self._dfs(jug1_amount - amount_to_pour, jug2_amount + amount_to_pour)

        # Pour from jug2 to jug1
        amount_to_pour = min(jug2_amount, self.jug1_capacity - jug1_amount)
        self._dfs(jug1_amount + amount_to_pour, jug2_amount - amount_to_pour)


# Example usage:
jug1_capacity = 5
jug2_capacity = 3
target_amount = 4

problem = WaterJugProblem(jug1_capacity, jug2_capacity, target_amount)
problem.solve()
