#include<bits/stdc++.h>
using namespace std;

class heap{
    int size;
    int arr[100];
    public:
    heap(){
        size = 0;
        arr[0] = -1;
    }
    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = i*2+1;
        int right = i*2+2;
        if(left<n && arr[largest] < arr[left]){
            largest = left;
        }
        if(right<n && arr[largest] < arr[right]){
            largest = right;
        }
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }


};
int main(){
    int k,n;
    cin>>k;
    char arr[50];
    cin >> arr; 
    n = strlen(arr);
    int temp[n];
    cout<<n;
    for (int i = 0; i < n; i++)
    {
        temp[i] = 0;
        for (int j = 1; j < n; j++)
        {
            if(arr[i] == arr[j]){
                temp[i] ++;
            }
        }
    }
    
    
return 0;
}