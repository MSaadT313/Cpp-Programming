#include<iostream>
#include<string>
using namespace std;

struct Product {
    string name, desc;
    float price;
    int avail;
};

void swap(Product &a, Product &b) {
    Product t = a; a = b; b = t;
}

int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low-1;
    for(int j=low;j<high;j++) {
        if(arr[j].price<=pivot) {
            i++; swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(Product arr[], int low, int high) {
    if(low<high) {
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main() {
    Product arr[3];
    for(int i=0;i<3;i++) cin >> arr[i].name >> arr[i].price >> arr[i].desc >> arr[i].avail;
    quickSort(arr,0,2);
    for(int i=0;i<3;i++)
        cout << arr[i].name << " " << arr[i].price << " " << arr[i].desc << " " << arr[i].avail << endl;
    return 0;
}
