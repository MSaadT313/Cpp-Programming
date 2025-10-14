#include<iostream>
using namespace std;
class Box{
    int* ptr;
    public:
    Box(int x){
        ptr = new int(x);
    }
    Box(const Box &other){        //without this it would be a shallow copy and address would be same
        ptr = new int(*other.ptr);
    }
    void display(){
        cout<<"\nptr : "<<ptr;
        cout<<"\nptr : "<<*ptr;
    }
    ~Box(){
        delete ptr;

    }
};
//for deep copy we have to explicitly define the copy constructor and tell him what to do with the value
int main(){
    Box b1(10);
    b1.display();
    Box b2 = b1;
    b2.display();
    return 0;
}