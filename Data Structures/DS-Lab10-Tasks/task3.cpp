#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2+1;
    int right = i*2+2;
    if(left<n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right< n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void build_heap(int arr[], int n){
    for (int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void heap_sort(int arr[], int n){
    build_heap(arr,n);
    for (int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }

}

int main(){
    int arr[] = {1,23,12,9,30,2,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given Array\n";
    for (int i = 0; i < n; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    int k;
    cout<<"Enter kth largest index: ";cin>>k;
    heap_sort(arr,n);
    reverse(arr,arr +n);
    
      cout<<"Kth largest number: "<<arr[k-1];
    
return 0;
}