#include<iostream>
using namespace std;
void heap_sort(int arr[], int n){
    int t = n;
    while(t>1){
        swap(arr[1],arr[n]);
        t--;
        heapify(arr,t,1);
    }
}
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2;
    int right = i*2 +1;
    if(left<=n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right<= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
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
return 0;
}