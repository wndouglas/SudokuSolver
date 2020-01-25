import json

class sudoku():
    def __init__(self, size):
        self.size = size
        self.board = []
        self.initialise_board()

    def initialise_board(self):
        for _ in range(0,self.size):
            row = [0]*self.size
            self.board.append(row)

    def fill_cell(self, row, col, entry):
        self.board[row - 1][col - 1] = entry

def fill_this_board(this_board):
    this_board.fill_cell(1, 4, 2)
    this_board.fill_cell(1, 5, 6)
    this_board.fill_cell(1, 7, 7)
    this_board.fill_cell(1, 9, 1)

    this_board.fill_cell(2, 1, 6)
    this_board.fill_cell(2, 2, 8)
    this_board.fill_cell(2, 5, 7)
    this_board.fill_cell(2, 8, 9)

    this_board.fill_cell(3, 1, 1)
    this_board.fill_cell(3, 2, 9)
    this_board.fill_cell(3, 6, 4)
    this_board.fill_cell(3, 7, 5)

    this_board.fill_cell(4, 1, 8)
    this_board.fill_cell(4, 2, 2)
    this_board.fill_cell(4, 4, 1)
    this_board.fill_cell(4, 8, 4)

    this_board.fill_cell(5, 3, 4)
    this_board.fill_cell(5, 4, 6)
    this_board.fill_cell(5, 6, 2)
    this_board.fill_cell(5, 7, 9)

    this_board.fill_cell(6, 2, 5)
    this_board.fill_cell(6, 6, 3)
    this_board.fill_cell(6, 8, 2)
    this_board.fill_cell(6, 9, 8)

    this_board.fill_cell(7, 3, 9)
    this_board.fill_cell(7, 4, 3)
    this_board.fill_cell(7, 8, 7)
    this_board.fill_cell(7, 9, 4)

    this_board.fill_cell(8, 2, 4)
    this_board.fill_cell(8, 5, 5)
    this_board.fill_cell(8, 8, 3)
    this_board.fill_cell(8, 9, 6)

    this_board.fill_cell(9, 1, 7)
    this_board.fill_cell(9, 3, 3)
    this_board.fill_cell(9, 5, 1)
    this_board.fill_cell(9, 6, 8)

def save_board_to_json(this_board):
    board_data = {"size" : this_board.size, "board" : this_board.board}
    with open('sample_board.json', 'w', encoding='utf-8') as f:
        json.dump(board_data, f, ensure_ascii=False, indent=4)

def main():
    N = 9
    this_board = sudoku(N)

    fill_this_board(this_board)
    save_board_to_json(this_board)

if __name__ == "__main__":
    main()
