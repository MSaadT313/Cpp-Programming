#include<iostream>
#include<queue>
using namespace std;
void heapify(int arr[], int n, int i){
    int smallest = i;
    int left = i*2+1;
    int right = i*2+2;
    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[ right]){
        smallest  = right;
    }
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, i, smallest);
    }
}
void heap_sort(int arr[], int n){
    int t = n;
    while(t>1){
        swap(arr[1],arr[n]);
        t--;
        heapify(arr,t,1);
    }
}
int main(){
    
return 0;
}