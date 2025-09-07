#include <iostream>
#include <string>
using namespace std;

int main() {
    string departments[] = {"SE", "AI", "CS", "DS"};
    int courses[] = {3, 4, 2, 1};
    double *gpas[4];

    for (int i = 0; i < 4; i++) {
        gpas[i] = new double[courses[i]];
    }

    for (int i = 0; i < 4; i++) {
        cout << "Enter GPAs for " << departments[i] << ": ";
        for (int j = 0; j < courses[i]; j++) {
            cin >> gpas[i][j];
        }
    }

    cout << "\nGPAs for core courses:\n";
    for (int i = 0; i < 4; i++) {
        cout << departments[i] << ": ";
        for (int j = 0; j < courses[i]; j++) {
            cout << gpas[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete[] gpas[i];
    }

    return 0;
}
