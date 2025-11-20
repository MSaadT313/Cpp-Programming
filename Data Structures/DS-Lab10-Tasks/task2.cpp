#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2+1;
    int right = i*2 +2;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n){
    for (int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    
}


void isBinaryHeap(int arr[], int n){
    for (int i = 0; i < (n-2)/2; i++)
    {
        int left = i*2+1;
        int right = i*2+2;
        if(arr[i]<arr[left] && arr[i]<arr[right]){
            cout<<"Not a Max heap"<<endl;
            return;
        }
    }  
}

int main(){
    int arr[] = {2,5,3,77,22,66,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 0; i < n; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    heap_sort(arr,n);
    for (int i = 0; i < n; i++)
      {
        cout<<arr[i]<<" ";
      }
return 0;
}