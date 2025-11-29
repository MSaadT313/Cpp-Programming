#include<iostream>
using namespace std;
class Node{
    public:
    int sum = 0;
    int a,b;
    Node* next;
    Node(int x, int y){
        a = x;
        b = y;
        next = nullptr;
    }
};
class Hashtable{
    public:
    Node* table[100];
    Hashtable(){
        for (int i = 0; i < 100; i++){
            table[i] = nullptr;
        }
    }
    int hashfunction(int s){
        return s%100;
    }
    bool insertandCheck(int a, int b){
        int s = a + b;
        int index = hashfunction(s);
        Node* temp = table[index];
        while (temp!= nullptr)
        {
            if (temp->a!=b && temp->a!=a && temp->b!=a && temp->b!=b)
            {
                cout << "Pairs found: (" << temp->a << "," << temp->b << ") and ("<< a << "," << b << ")" << endl;
                return true;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(a,b);
        newNode->next = table[index];
        table[index] = newNode;
        return false;
    }
};

void FindSumEQualpairs(int arr[], int n){
    Hashtable hashtable;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(hashtable.insertandCheck(arr[i],arr[j])){
                return;
            }
        }
        
    }
    cout<<"no pair found";
}

int main(){
       int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    FindSumEQualpairs(arr1, n1); 

    int arr2[] = {3, 4, 7, 1, 12, 9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    FindSumEQualpairs(arr2, n2); 

    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    FindSumEQualpairs(arr3, n3); 


return 0;
}