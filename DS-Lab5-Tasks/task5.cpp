#include <iostream>
using namespace std;

int sum(int** arr, int rows, int* cols, int i = 0, int j = 0) {
    if (i == rows) return 0;
    if (j == cols[i]) return sum(arr, rows, cols, i + 1, 0);
    return arr[i][j] + sum(arr, rows, cols, i, j + 1);
}

int main() {
    int rows;
    cin >> rows;
    int* cols = new int[rows];
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        cin >> cols[i];
        arr[i] = new int[cols[i]];
        for (int j = 0; j < cols[i]; j++) cin >> arr[i][j];
    }
    cout << sum(arr, rows, cols) << endl;
}
