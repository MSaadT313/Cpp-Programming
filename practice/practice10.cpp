#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "Constructor of A called\n"; }
    A(int x) { cout << "Parameterized Constructor of A: " << x << endl; }
};

class B {
public:
    B() { cout << "Constructor of B called\n"; }
    B(int y) { cout << "Parameterized Constructor of B: " << y << endl; }
};

// Multiple Inheritance
class C : public B, public A {
public:
    C() {
        cout << "Constructor of C called\n";
    }

    C(int x, int y) : B(x), A(y) {
        cout << "Parameterized Constructor of C: " << x + y << endl;
    }
};

int main() {
    cout << "Creating obj1:\n";
    C obj1;

    cout << "\nCreating obj2:\n";
    C obj2(10, 20);

    return 0;
}
