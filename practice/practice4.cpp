#include <iostream>
using namespace std;

class base {
public:
    int i, b;
    // Constructor to initialize i and b
    base(int i, int b) {
        this->i = i;
        this->b = b;
    }
};

class derived1 : public base {
public:
    int j, c;
    // Constructor to initialize base class and derived1 members
    derived1(int i, int b, int j, int c) : base(i, b) {
        this->j = j;
        this->c = c;
    }
    void showData1() {
        cout << "i: " << i << endl;
        cout << "b: " << b << endl;
        cout << "j: " << j << endl;
        cout << "c: " << c << endl;
    }
};

class derived2 : public derived1 {
public:
    // Constructor to initialize derived1 class
    derived2(int i, int b, int j, int c) : derived1(i, b, j, c) {}
    
    void showData2() {
        cout << "Derived2 class data: " << c << endl;
    }
};

int main() {
    // Create an object of derived2 and initialize it using the constructor
    derived2 d2(4, 5, 6, 7);
    
    d2.showData1();
    d2.showData2();

    return 0;
}
