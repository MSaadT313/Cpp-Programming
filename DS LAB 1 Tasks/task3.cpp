#include <iostream>
using namespace std;

class ShallowBox {
private:
    int* value;
public:
    ShallowBox(int val) {
        value = new int(val);
    }
    void display() const {
        cout << "Value: " << *value << " (Address: " << value << ")" << endl;
    }
    ~ShallowBox() {
        delete value;
    }
};

class DeepBox {
private:
    int* value;
public:
    DeepBox(int val) {
        value = new int(val);
    }
    DeepBox(const DeepBox& other) {
        value = new int(*other.value);
    }
    DeepBox& operator=(const DeepBox& other) {
        if (this != &other) {
            delete value;
            value = new int(*other.value);
        }
        return *this;
    }
    ~DeepBox() {
        delete value;
    }
    void display() const {
        cout << "Value: " << *value << " (Address: " << value << ")" << endl;
    }
    void setValue(int val) {
        *value = val;
    }
};

int main() {
    cout << "Shallow Copy Example" << endl;
    ShallowBox s1(10);
    s1.display();
    ShallowBox s2 = s1;
    s2.display();
    cout << "When both objects are destroyed, double deletion occurs" << endl;

    cout << "\nDeep Copy Example" << endl;
    DeepBox d1(10);
    d1.display();
    DeepBox d2 = d1;
    d2.display();
    d1.setValue(20);
    cout << "After changing d1:" << endl;
    d1.display();
    d2.display();
    return 0;
}
