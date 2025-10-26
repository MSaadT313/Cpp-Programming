#include<iostream>
#include<algorithm>
using namespace std;

void countingSort(int arr[], int n, int exp, bool desc) {
    int output[n];
    int count[10] = {};
    for(int i=0;i<n;i++) count[(arr[i]/exp)%10]++;
    if(desc) for(int i=8;i>=0;i--) count[i] += count[i+1];
    else for(int i=1;i<10;i++) count[i] += count[i-1];
    for(int i=n-1;i>=0;i--) {
        int idx = (arr[i]/exp)%10;
        output[count[idx]-1] = arr[i];
        count[idx]--;
    }
    for(int i=0;i<n;i++) arr[i]=output[i];
}

void radixSort(int arr[], int n, bool desc) {
    int mx = *max_element(arr, arr+n);
    for(int exp=1;mx/exp>0;exp*=10)
        countingSort(arr,n,exp,desc);
}

int main() {
    int arr[] = {170,45,75,90,802,24,2,66};
    int n = 8;
    radixSort(arr,n,0);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
    radixSort(arr,n,1);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
