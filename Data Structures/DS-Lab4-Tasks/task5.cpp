/*Given an array with birth years of children born in 2022, 2023, and 2024, the task is to
sort the array so that all children born in 2022 come first, followed by those born in 2023, and
finally those born in 2024.
Input: {2022, 2023, 2024, 2022, 2023, 2024}
Output: {2022, 2022, 2023, 2023, 2024, 2024}
Explanation: {2022, 2022, 2023, 2023, 2024, 2024} shows that all the 2022 birth years come
first, followed by the 2023 , and then all the 2024 birth years at the end.*/
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2022, 2023, 2024, 2022, 2023, 2024};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count2022=0,count2023=0,count2024=0;
    for(int i=0;i<n;i++){
        if(arr[i]==2022) count2022++;
        else if(arr[i]==2023) count2023++;
        else count2024++;
    }
    int k=0;
    for(int i=0;i<count2022;i++) arr[k++]=2022;
    for(int i=0;i<count2023;i++) arr[k++]=2023;
    for(int i=0;i<count2024;i++) arr[k++]=2024;
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
