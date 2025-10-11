#include <iostream>
using namespace std;

const int N = 4;
int maze[N][N] = {
    {1, 1, 1, 1},
    {0, 0, 0, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1}
};
int sol[N][N];

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMaze(int x, int y) {
    if (x == 0 && y == 0) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(x, y)) {
        sol[x][y] = 1;
        if (solveMaze(x - 1, y)) return true; // up
        if (solveMaze(x, y + 1)) return true; // right
        if (solveMaze(x + 1, y)) return true; // down
        if (solveMaze(x, y - 1)) return true; // left
        sol[x][y] = 0;
    }
    return false;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = 0;

    if (solveMaze(3, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No path found" << endl;
    }
}
