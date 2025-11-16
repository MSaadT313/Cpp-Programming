#include<iostream>
using namespace std;

class Heap{
   public:
   int arr[100];
   int size;
   Heap(){
    size = 0;
    arr[0] = -1;
    }

    void insert(int val){
    size ++;
    int index = size;
    arr[index] = val;
    while(index>1){
        int parent = index/2;
        if(arr[parent]<arr[index]){
        swap(arr[parent], arr[index]);
        index = parent;
        }
        else{
             return;
            }
    }
   }
   void print(){
      for (int i = 1; i <= size; i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;
      }



    void deletefromheap(){
        //st-1
         arr[1]=arr[size];
         //st-2
         size--;
         //st-3
         int i = 1;
         int max;
         while(i<size){
            int leftchild = i*2;
            int rightchild = i*2+1;
            if(leftchild>rightchild){
                max = leftchild;
            }
            else{
                max = rightchild;
            }
            
            if(max<size && arr[max]>arr[i]){
                swap(arr[max], arr[i]);
                i = max;
            }
            else{
                return;
            } 
         }
        }
    void update_key(int i, int new_val){
        arr[i] = new_val;
         while(i>0 && i<size){
            int parent = i/2;
            int max;
            int leftchild = i*2;
            int rightchild = i*2+1;
            if(arr[parent]>arr[i]){
                swap(arr[parent],arr[i]);
                i = parent;
                break;
            }
            if(leftchild>rightchild){
                max = leftchild;
            }
            else{
                max = rightchild;
            }
            
            if(max<size && arr[max]>arr[i]){
                swap(arr[max], arr[i]);
                i = max;
                break;
            }
            else{
                return;
            } 
         }
            
        }
    };

int main()
{
    cout<<"Given Heap Array: \n";
    Heap h1;
    h1.insert(8);
    h1.insert(7);
    h1.insert(6);
    h1.insert(5);
    h1.insert(4);
    h1.print();
    h1.update_key(3,9);
    h1.print();
    h1.deletefromheap();
    h1.print();
    return 0;
}