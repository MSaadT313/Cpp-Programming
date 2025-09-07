#include <iostream>
#include <string>

class Base {
public:
    Base() { std::cout << "Base default constructor" << std::endl; }
    Base(int x) : val(x) { std::cout << "Base parameterized constructor with " << val << std::endl; }
protected:
    int val;
};

class Derived : public Base {
public:
    using Base::Base; // Inherit all constructors from Base
 
    Derived() : extra(0) { std::cout << "Derived default constructor (after base)" << std::endl; }
    Derived(int x) : Base(x), extra(0) { std::cout << "Derived parameterized constructor (explicit)" << std::endl; }

private:
    int extra;
};

class EvenMoreDerived : public Derived {
public:
    using Derived::Derived; // Inherit all constructors from Derived
    EvenMoreDerived() : moreExtra(0) { std::cout << "EvenMoreDerived default constructor (after derived)" << std::endl; }
private:
    int moreExtra;
};

int main() {
    Derived d1; // Calls Base default constructor, then Derived default constructor
    Derived d2(5); // Calls Base parameterized constructor with 5, then Derived parameterized constructor (explicit)
    EvenMoreDerived emd1; // Calls Base default, Derived default, EvenMoreDerived default
    EvenMoreDerived emd2(10); // Calls Base parameterized with 10, then Derived parameterized (inherited)
    return 0;
}