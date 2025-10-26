#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int cmpCount = 0;
void swap(int &a, int &b) { int t=a; a=b; b=t; }

int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low], i=low, j=high;
    while(i<j) {
        while(arr[i]<=pivot && i<high) { cmpCount++; i++; }
        while(arr[j]>pivot && j>low) { cmpCount++; j--; }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

int partitionRandom(int arr[], int low, int high) {
    int idx = low + rand()%(high-low+1);
    swap(arr[high],arr[idx]);
    int pivot=arr[high],i=low-1;
    for(int j=low;j<high;j++) {
        cmpCount++;
        if(arr[j]<=pivot) {
            i++; swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

int partitionMiddle(int arr[], int low, int high) {
    int mid=low+(high-low)/2;
    swap(arr[mid],arr[high]);
    int pivot=arr[high],i=low-1;
    for(int j=low;j<high;j++) {
        cmpCount++;
        if(arr[j]<=pivot) {
            i++; swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

int partitionMedian(int arr[], int low, int high) {
    int mid=low+(high-low)/2;
    int a=arr[low],b=arr[mid],c=arr[high],med;
    if((a>=b&&a<=c)||(a<=b&&a>=c)) med=low;
    else if((b>=a&&b<=c)||(b<=a&&b>=c)) med=mid;
    else med=high;
    swap(arr[high],arr[med]);
    int pivot=arr[high],i=low-1;
    for(int j=low;j<high;j++) {
        cmpCount++;
        if(arr[j]<=pivot) { i++; swap(arr[i],arr[j]); }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high, int type) {
    if(low<high) {
        int pi;
        if(type==0) pi=partitionFirst(arr,low,high);
        else if(type==1) pi=partitionRandom(arr,low,high);
        else if(type==2) pi=partitionMiddle(arr,low,high);
        else pi=partitionMedian(arr,low,high);
        quickSort(arr,low,pi-1,type);
        quickSort(arr,pi+1,high,type);
    }
}

int main() {
    int arrSorted[]={1,2,3,4,5,6,7,8,9,10};
    int arrRev[]={10,9,8,7,6,5,4,3,2,1};
    int arrRand[]={3,7,2,1,9,8,10,4,6,5};
    for(int t=0;t<4;t++) {
        int a1[10],a2[10],a3[10];
        for(int i=0;i<10;i++) a1[i]=arrSorted[i],a2[i]=arrRev[i],a3[i]=arrRand[i];
        cmpCount=0; quickSort(a1,0,9,t); cout<<"Sorted "<<t<<" "<<cmpCount<<endl;
        cmpCount=0; quickSort(a2,0,9,t); cout<<"Reverse "<<t<<" "<<cmpCount<<endl;
        cmpCount=0; quickSort(a3,0,9,t); cout<<"Random "<<t<<" "<<cmpCount<<endl;
    }
    return 0;
}
