#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check same column or diagonals
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(int board[], int n, int row = 0) {
    if (row == n) {
        // All queens are placed successfully
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // Place queen

            // Recursively place next queen
            if (solveNQueens(board, n, row + 1)) {
                return true;
            }

            // Backtrack if not possible
            board[row] = -1;
        }
    }
    return false;
}

void printSolution(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    int board[10]; // max size
    for (int i = 0; i < n; i++)
        board[i] = -1;

    if (solveNQueens(board, n)) {
        cout << "Solution found:\n";
        printSolution(board, n);
    } else {
        cout << "No solution exists.";
    }

    return 0;
}
