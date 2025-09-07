#include <iostream>
#include <new> // for std::bad_alloc
using namespace std;

int main() {
    try {
        int* bigArray = new int[1000000000000]; // very large array
    } catch (bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << endl;
    }

    return 0;
}
