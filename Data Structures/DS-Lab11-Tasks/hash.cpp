#include <iostream>
using namespace std;

struct PairSum {
    int a, b;
    int sum;
};

void findPairs(int arr[], int n) {
    PairSum pairs[1000];  // array to store previous pairs (adjust size if needed)
    int count = 0;         // number of stored pairs

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int s = arr[i] + arr[j];

            // Check all previous pairs
            for (int k = 0; k < count; k++) {
                if (pairs[k].sum == s) {
                    // Check all four numbers are distinct
                    if (pairs[k].a != arr[i] && pairs[k].a != arr[j] &&
                        pairs[k].b != arr[i] && pairs[k].b != arr[j]) {
                        cout << "(" << pairs[k].a << ", " << pairs[k].b << ") and "
                             << "(" << arr[i] << ", " << arr[j] << ")" << endl;
                        return;
                    }
                }
            }

            // Store this pair
            pairs[count].a = arr[i];
            pairs[count].b = arr[j];
            pairs[count].sum = s;
            count++;
        }
    }

    cout << "No pairs found" << endl;
}

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    findPairs(arr1, n1);  // Output: (3,8) and (4,7)

    int arr2[] = {3, 4, 7, 1, 12, 9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    findPairs(arr2, n2);  // Output: (4,12) and (7,9)

    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    findPairs(arr3, n3);  // Output: No pairs found

    return 0;
}
