#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim) {
    if (dim == 1) {
        int s = 0;
        for (int i = 0; i < sizes[0]; i++) s += arr[i][0];
        return s;
    }
    int s = 0;
    for (int i = 0; i < sizes[0]; i++) {
        s += recursiveArraySum((int**)arr[i], sizes + 1, dim - 1);
    }
    return s;
}

int main() {
    int sizes[3] = {2, 2, 3};  

    int*** arr = new int**[sizes[0]];
    for (int i = 0; i < sizes[0]; i++) {
        arr[i] = new int*[sizes[1]];
        for (int j = 0; j < sizes[1]; j++) {
            arr[i][j] = new int[sizes[2]];
            for (int k = 0; k < sizes[2]; k++) {
                cin >> arr[i][j][k];  
            }
        }
    }

    int sum = recursiveArraySum((int**)arr, sizes, 3);
    cout << sum << endl;
}
