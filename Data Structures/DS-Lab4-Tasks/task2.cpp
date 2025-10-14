/*Let arr[9] = { 20, 12, 15, 2, 10, 1, 13, 9, 5} now sort the array in such a way that
maximum element must be at middle of the array and rest of array must be sorted in ascending
order do this using insertion sort.*/
#include <iostream>
using namespace std;

int main() {
    int arr[9] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
    for(int i=1;i<9;i++){
        int key=arr[i],j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    int maxVal=arr[8];
    for(int i=8;i>4;i--){
        arr[i]=arr[i-1];
    }
    arr[4]=maxVal;
    cout<<"Final array: ";
    for(int i=0;i<9;i++) cout<<arr[i]<<" ";
    return 0;
}
