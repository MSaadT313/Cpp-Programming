/*Write a Program that ask user to enter 10 elements and finds the 4 minimum elements
from given array using selection Sort.*/
#include <iostream>
using namespace std;

int main() {
    int arr[10];
    for(int i=0;i<10;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    for(int i=0;i<10-1;i++){
        int minIndex=i;
        for(int j=i+1;j<10;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
    cout<<"The 4 minimum elements are: ";
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
