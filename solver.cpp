#include <iostream>
using namespace std;

bool isCellEmpty(int board[9][9], int& row, int& col);
bool isValidMove(int board[9][9], int row, int col, int num);
bool solveSudoku(int board[9][9]);

int main() {
    int board[9][9] = {0};

    cout << "Enter the Sudoku puzzle (use 0 for empty cells):\n";
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            int num;
            while (true) {
                cout << "Enter value for cell (" << row + 1 << ", " << col + 1 << "): ";
                cin >> num;
                if (num >= 0 && num <= 9) {
                    board[row][col] = num;
                    break;
                } else {
                    cout << "Invalid input. Please enter a number between 0 and 9.\n";
                }
            }
        }
    }

    if (solveSudoku(board)) {
        cout << "The solved Sudoku puzzle is:\n";
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cout << board[row][col] << " ";
        }
        cout << "\n";
    }

    return 0;
}

bool isCellEmpty(int board[9][9], int& row, int& col) {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool isValidMove(int board[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int gridRow = row - row % 3;
    int gridCol = col - col % 3;
    for (int i = gridRow; i < gridRow + 3; ++i) {
        for (int j = gridCol; j < gridCol + 3; ++j) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int board[9][9]) {
    int row, col;

    if (!isCellEmpty(board, row, col)) {
        return true;
    }

    for (int num = 1; num <= 9; ++num) {
        if (isValidMove(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board)) {
                return true;
            }

            board[row][col] = 0;
        }
    }
    return false;
}