#include <iostream>
using namespace std;

const int N = 4;

int maze[N][N] = {
    {1, 1, 1, 1},
    {0, 0, 0, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1}
};

int sol[N][N] = {0};

bool isSafe(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1;
}

bool solveMaze(int x, int y) {
    if (x == 2 && y == 0) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(x, y)) {
        sol[x][y] = 1;

        if (solveMaze(x + 1, y)) return true;
        if (solveMaze(x, y + 1)) return true;
        if (solveMaze(x - 1, y)) return true;
        if (solveMaze(x, y - 1)) return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    if (solveMaze(0, 0)) {
        cout << "Path to target found:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No path found!\n";
    }
    return 0;
}