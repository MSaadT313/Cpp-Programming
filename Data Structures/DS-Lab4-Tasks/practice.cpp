/*
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n; 
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
        return 0;
}
    */
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n; 
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        int Smallest = i;
        for (int j = i+1; j< n; j++)
        {
            if(arr[j]<arr[Smallest]){
                Smallest = j;
            }
        }
        swap(arr[i],arr[Smallest]);
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}