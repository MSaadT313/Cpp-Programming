#include <iostream>
using namespace std;
class parent{
    public:
    parent(){};
    void display1(){
        cout<<"Parent class called"<<endl;
    }
};

// Create a demo class
class A {
public:
    int x;
    A(){}
    A(parent obj){
       cout<<"Enter"<<endl;
    }
};

int main() {
  
    A a1;
    a1.x = 10;
    cout << "a1's x = " << a1.x << endl;

    A a2(a1);
    a2.x = 23;
    cout << "a2's x = " << a2.x;

cout << "a1's x = " << a1.x << endl;
    return 0;
}