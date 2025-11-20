#include<iostream>
#include<queue>
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

    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = i*2;
        int right = i*2 + 1;
        if(left <= n && arr[largest] < arr[left]){
            largest  = left;
        }
        if(right <= n && arr[largest] < arr[right]){
            largest = right;
        }
        if(largest != i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }
    void heap_sort(int arr[], int n){
    int t = n;
    while(t>1){
        swap(arr[t],arr[1]);
        t--;
        heapify(arr,t,1);
    }
}

int main()
{
    // cout<<"Given Heap Array: \n";
    Heap h1;
    h1.insert(8);
    h1.insert(7);
    h1.insert(6);
    h1.insert(5);
    h1.insert(4);
    // h1.print();
    int arr[] = {-1,5,36,3,11,67,22};
    int n = 6;
    for (int i = n/2; i > 0; i--)
    {
        heapify(arr,n,i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Heapsort Functions called"<<endl;
    heap_sort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Max Heap";
    priority_queue<int> pq;
    pq.push(42);
    pq.push(3);
    pq.push(45);
    pq.push(411);
    pq.push(46);
    pq.push(234);
    cout<<"top element in priority queue "<<pq.top();
    cout<<"\nSize "<<pq.size();

    cout<<endl<<"Min heap\n";
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(42);
    minheap.push(3);
    minheap.push(45);
    minheap.push(411);
    minheap.push(46);
    minheap.push(234);
    cout<<"top element in priority queue "<<minheap.top();
    cout<<"\nSize "<<minheap.size();
    return 0;
}