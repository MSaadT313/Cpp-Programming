#include <iostream>
using namespace std;

#define N 4  

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

bool solve(int board[N][N], int row) {
    if (row == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << (board[i][j] ? "Q " : "- ");
            cout << endl;
        }
        cout << endl;
        return true;
    }
    bool found = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            found = solve(board, row + 1) || found;
            board[row][col] = 0;
        }
    }
    return found;
}

int main() {
    int board[N][N] = {0};
    if (!solve(board, 0))
        cout << "No solution exists" << endl;
}
