//heapify algo for min heap
#include<iostream>
using namespace std;
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2+1;
    int right = i*2+2;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[ right]){
        largest  = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
int main(){
    int arr[] = {3,5,9,6,8,20,10,12,18,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Min Heap Array: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for (int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }
    cout<<"Max Heap Array: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
