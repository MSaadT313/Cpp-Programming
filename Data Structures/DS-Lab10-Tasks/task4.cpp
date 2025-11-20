//heapify algo for min heap
#include<iostream>
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
int main(){
    int arr[] = {1,435,3,24,35,2,45};
    int n =7;
    for (int i = n/2; i > 0; i--)
    {
        heapify(arr,n,i);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
