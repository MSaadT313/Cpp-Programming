#include<iostream>
#include<algorithm>
using namespace std;

void mergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        int n1 = m-l+1, n2 = r-m;
        int L[n1], R[n2];
        for(int i=0;i<n1;i++) L[i]=arr[l+i];
        for(int i=0;i<n2;i++) R[i]=arr[m+1+i];
        int i=0,j=0,k=l;
        while(i<n1 && j<n2) {
            if(L[i]<=R[j]) arr[k++]=L[i++];
            else arr[k++]=R[j++];
        }
        while(i<n1) arr[k++]=L[i++];
        while(j<n2) arr[k++]=R[j++];
    }
}

void countingSort(int arr[], int n, int exp) {
    int output[n], count[10] = {};
    for(int i=0;i<n;i++) count[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++) count[i] += count[i-1];
    for(int i=n-1;i>=0;i--) {
        int idx=(arr[i]/exp)%10;
        output[count[idx]-1]=arr[i];
        count[idx]--;
    }
    for(int i=0;i<n;i++) arr[i]=output[i];
}

void radixSort(int arr[], int n) {
    int mx = *max_element(arr,arr+n);
    for(int exp=1;mx/exp>0;exp*=10)
        countingSort(arr,n,exp);
}

int main() {
    int arr1[10], arr2[10], merged[20];
    for(int i=0;i<10;i++) cin >> arr1[i];
    for(int i=0;i<10;i++) cin >> arr2[i];
    for(int i=0;i<10;i++) merged[i]=arr1[i];
    for(int i=0;i<10;i++) merged[i+10]=arr2[i];
    radixSort(merged,20);
    for(int i=0;i<20;i++) cout << merged[i] << " ";
    cout << endl;
    mergeSort(merged,0,19);
    for(int i=0;i<20;i++) cout << merged[i] << " ";
    cout << endl;
    return 0;
}
