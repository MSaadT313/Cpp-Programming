/*Task#7: From array mentioned below find the following names and their index using binary
search as well as linear search and count the number of steps on each finding element by using
both techniques and analyze which technique is getting more time:
• Aftab
• Rizwan
• Tariq*/
#include <iostream>
#include <string>
using namespace std;

int linearSearch(string arr[], int n, string key, int &steps) {
    steps = 0;
    for(int i=0;i<n;i++){
        steps++;
        if(arr[i]==key) return i;
    }
    return -1;
}

int binarySearch(string arr[], int n, string key, int &steps) {
    int left = 0, right = n-1;
    steps = 0;
    while(left <= right) {
        steps++;
        int mid = left + (right-left)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) left = mid+1;
        else right = mid-1;
    }
    return -1;
}

int main() {
    string arr[] = {"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Taufiq", "Yasin", "Zulfiqar"};
    int n = sizeof(arr)/sizeof(arr[0]);

    string keys[] = {"Aftab", "Rizwan", "Tariq"};
    int m = 3;

    for(int i=0;i<m;i++){
        int stepsLinear, stepsBinary;
        int posLinear = linearSearch(arr,n,keys[i],stepsLinear);
        int posBinary = binarySearch(arr,n,keys[i],stepsBinary);

        cout<<"Finding "<<keys[i]<<":\n";
        if(posLinear != -1) cout<<"  Linear Search -> Index: "<<posLinear<<", Steps: "<<stepsLinear<<"\n";
        else cout<<"  Linear Search -> Not Found, Steps: "<<stepsLinear<<"\n";

        if(posBinary != -1) cout<<"  Binary Search -> Index: "<<posBinary<<", Steps: "<<stepsBinary<<"\n";
        else cout<<"  Binary Search -> Not Found, Steps: "<<stepsBinary<<"\n";

        cout<<endl;
    }
    return 0;
}
