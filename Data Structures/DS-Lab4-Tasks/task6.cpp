/*Implement the array given in the heading of binary search topic, sort it and find the
value corresponding to to your last two digits of the roll number
(if its not in the array add a value somewhere in between the array) and find it via binary search.*/
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n-1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {23, 1, 45, 78, 56, 92, 13, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,n);

    int key;
    cout<<"Enter last two digits of your roll number: ";
    cin>>key;

    int pos = binarySearch(arr,n,key);

    if(pos==-1){
        int newArr[20];
        int k=0;
        bool inserted=false;
        for(int i=0;i<n;i++){
            if(!inserted && arr[i]>key){
                newArr[k++]=key;
                inserted=true;
            }
            newArr[k++]=arr[i];
        }
        if(!inserted) newArr[k++]=key;
        n=k;
        cout<<"Array after inserting "<<key<<": ";
        for(int i=0;i<n;i++) cout<<newArr[i]<<" ";
        cout<<endl;
        pos=binarySearch(newArr,n,key);
        cout<<"Found at index: "<<pos<<endl;
    } else {
        cout<<"Found "<<key<<" at index: "<<pos<<endl;
    }
    return 0;
}
