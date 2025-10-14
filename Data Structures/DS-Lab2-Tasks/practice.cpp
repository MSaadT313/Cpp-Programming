#include<iostream>
using namespace std;
int main(){
    int row;
    int* columns;
    cout<<"Enter the size of rows: ";
    cin>>row;
    int** arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        cout<<"Enter the size of column "<<i+1<<": ";
        cin>>columns[i];
        int size = columns[i];
        arr[i] = new int(size);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizeof(arr[i]); j++)
        {
            cout<<"Enter the value of element is row "<<i+1<<" and in column "<<j+1;
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0;j < *columns; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    delete[] arr;
    return 0;
}