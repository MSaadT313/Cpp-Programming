#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n) {
    if (x < n && y < n && arr[x][y] == 1) {
        return true;
    }
    return false;
}

bool ratInMaze(int** arr, int x, int y, int n, int** solArr) {
    // Base condition — reached destination
    if (x == n - 1 && y == n - 1) {
        solArr[x][y] = 1;
        return true;
    }

    // Check if current cell is safe
    if (isSafe(arr, x, y, n)) {
        solArr[x][y] = 1; // include this cell in path

        // Move right
        if (ratInMaze(arr, x + 1, y, n, solArr)) {
            return true;
        }

        // Move down
        if (ratInMaze(arr, x, y + 1, n, solArr)) {
            return true;
        }

        // Backtrack
        solArr[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    int n = 4;
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    // Create dynamic 2D arrays
    int** arr = new int*[n];
    int** solArr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = maze[i][j];
            solArr[i][j] = 0;
        }
    }

    cout << "Path found: " << (ratInMaze(arr, 0, 0, n, solArr) ? "Yes" : "No") << endl;

    cout << "\nSolution Path:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << solArr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
