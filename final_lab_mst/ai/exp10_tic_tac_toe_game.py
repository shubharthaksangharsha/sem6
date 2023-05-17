class TicTacToe:
    def __init__(self):
        self.board = [' '] * 9
        self.player1 = 'X'
        self.player2 = 'O'
        self.current_player = None

    def print_board(self):
        print('-------------')
        for i in range(3):
            print('|', self.board[i * 3], '|', self.board[i * 3 + 1], '|', self.board[i * 3 + 2], '|')
            print('-------------')

    def make_move(self, position, player):
        self.board[position] = player

    def is_valid_move(self, position):
        return self.board[position] == ' '

    def is_board_full(self):
        return ' ' not in self.board

    def check_winner(self):
        winning_positions = (
            [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Rows
            [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Columns
            [0, 4, 8], [2, 4, 6]  # Diagonals
        )
        for positions in winning_positions:
            if self.board[positions[0]] == self.board[positions[1]] == self.board[positions[2]] != ' ':
                return self.board[positions[0]]
        return None

    def switch_players(self):
        self.current_player = self.player2 if self.current_player == self.player1 else self.player1

    def minimax(self, depth, maximizing_player):
        if self.check_winner() == self.player2:
            return 1
        elif self.check_winner() == self.player1:
            return -1
        elif self.is_board_full():
            return 0

        if maximizing_player:
            max_eval = float('-inf')
            for position in self.get_empty_positions():
                self.make_move(position, self.player2)
                eval_score = self.minimax(depth + 1, False)
                self.make_move(position, ' ')
                max_eval = max(max_eval, eval_score)
            return max_eval
        else:
            min_eval = float('inf')
            for position in self.get_empty_positions():
                self.make_move(position, self.player1)
                eval_score = self.minimax(depth + 1, True)
                self.make_move(position, ' ')
                min_eval = min(min_eval, eval_score)
            return min_eval

    def get_best_move(self):
        best_score = float('-inf')
        best_move = None
        for position in self.get_empty_positions():
            self.make_move(position, self.player2)
            score = self.minimax(0, False)
            self.make_move(position, ' ')
            if score > best_score:
                best_score = score
                best_move = position
        return best_move

    def get_empty_positions(self):
        return [i for i, x in enumerate(self.board) if x == ' ']

    def play_vs_computer(self):
        print("Welcome to Tic Tac Toe!")
        self.print_board()
        self.current_player = input("Enter the starting player (1 for Player, 2 for Computer): ")
        while not self.is_board_full():
            if self.current_player == '1':
                position = int(input("Player's turn. Enter your move (0-8): "))
                if not self.is_valid_move(position):
                    print("Invalid move. Try again.")
                    continue
                self.make_move(position, self.player1)
            else:
                print("Computer's turn...")
                position = self.get_best_move()
                self.make_move(position, self.player2)

            self.print_board()
            winner = self.check_winner()
            if winner:
                if winner == self.player1:
                    print("Player wins!")
                else:
                    print("Computer wins!")
                return
            elif self.is_board_full():
                print("It's a tie!")
                return

            self.current_player = '1' if self.current_player == '2' else '2'


    def play_player_vs_player(self):
        print("Welcome to Tic Tac Toe!")
        self.print_board()
        self.current_player = self.player1
        while not self.is_board_full():
            position = int(input(f"Player {self.current_player}'s turn. Enter your move (0-8): "))
            if not self.is_valid_move(position):
                print("Invalid move. Try again.")
                continue
            self.make_move(position, self.current_player)
            self.print_board()
            winner = self.check_winner()
            if winner:
                print(f"Player {winner} wins!")
                return
            elif self.is_board_full():
                print("It's a tie!")
                return
            self.current_player = self.player2 if self.current_player == self.player1 else self.player1


if __name__ == '__main__':
    game = TicTacToe()
    mode = input("Select the game mode (1 for Player vs Computer, 2 for Player vs Player): ")
    if mode == '1':
        game.play_vs_computer()
    elif mode == '2':
        game.play_player_vs_player()
    else:
        print("Invalid mode. Please try again.")
